#ifndef _VEX_SIMD_H
#define _VEX_SIMD_H


#define _UI8						unsigned char
#define _UI16						unsigned short
#define _UI32						unsigned int

#define _OP_GROUP_MASK				(1 << 6)
#define _OP_GROUP_A					0
#define _OP_GROUP_B					(1 << 6)

/*** Subword sizes ***/
#define _OP_NSUB_MASK				(1 << 5)
#define _OP_NSUB_2					0
#define _OP_NSUB_4					(1 << 5)
#define _isOP_2(opcode)				(((opcode) & _OP_NSUB_MASK) == _OP_NSUB_2)
#define _isOP_4(opcode)				(((opcode) & _OP_NSUB_MASK) == _OP_NSUB_4)
#define _GET_NSUB(opcode)			((opcode) & _OP_NSUB_MASK)

/*** PACK - EXT ***/
#define _MASK_8						((_UI32)0xFF)
#define _MASK_16					((_UI32)0xFFFF)
#define _MASK_32					((_UI32)0xFFFFFFFF)
/* !!! VEX is BIG Endian !!! 
 * e0, e1 represent subword 0 and subword 1 respectively.
 * e0 will be stored as MS and e1 as LS
 */
#define _EXT32_16(v, n)				(_UI16)((v >> ((1-n)*16)) /*& _MASK_16*/)
#define _EXT32_8(v, n)				(_UI8)((v >> ((3-n)*8)) /*& _MASK_8*/)
#define _PACK32_16(e0, e1)			(_UI32)(((_UI16)(e0) << 16) + (_UI16)(e1))
#define _PACK32_8(e0, e1, e2, e3)	(_UI32)(((_UI8)(e0) << 24) + ((_UI8)(e1) << 16) + ((_UI8)(e2) << 8) + (_UI8)(e3))

/*** Operation types (subword type- independent) ***/
#define _OP_TYPE_MASK				0x7F  /*group included*/
/* GROUP A */
#define _ADD						1 | _OP_GROUP_A
#define _SUB						2 | _OP_GROUP_A
#define _SHR						3 | _OP_GROUP_A
#define _SHL						4 | _OP_GROUP_A
#define _SFL						5 | _OP_GROUP_A
#define _PCK						6 | _OP_GROUP_A
#define _EXT						7 | _OP_GROUP_A
#define _ADDI						8 | _OP_GROUP_A
#define _SUBI						9 | _OP_GROUP_A
#define _SHRI						10 | _OP_GROUP_A
#define _SHLI						11 | _OP_GROUP_A
/* GROUP B */
#define _MUL						1 | _OP_GROUP_B
#define _DIV						2 | _OP_GROUP_B
#define _MULI						3 | _OP_GROUP_B
#define _DIVI						4 | _OP_GROUP_B
#define _SPROD						5 | _OP_GROUP_B

/* extract operation from opcode */
#define _GET_OP(opcode)				((opcode) & (_OP_TYPE_MASK) & (~_OP_NSUB_MASK))

/*** Shuffle permutations (3 bits per destination subword) ***/
#define _SFL_PERM_MASK				(0xFFF)
#define _SFL_SUB0_MASK				(0x007)

#define _SFL_SUBn_MASK(n)			(0x007 << (3*n))
#define SFL_SRC0					0
#define SFL_SRC1					1
#define SFL_SRC2					2
#define SFL_SRC3					3
#define SFL_SRC4					4
#define SFL_SRC5					5
#define SFL_SRC6					6
#define SFL_SRC7					7
/* Encode permutation given the source of each output subword */
#define _SFL_PERM_CODE(r3,r2,r1,r0)	((r3 << 9) | (r2 << 6) | (r1 << 3) | r0)
/* extract shuffle permutaion from opcode */
#define _GET_SFL_SUB(sflperm,n)		(((sflperm) & _SFL_SUBn_MASK(n)) >> (3*n))


/*** OPCODES ***/
#define ADD_2						_ADD | _OP_NSUB_2
#define SUB_2						_SUB | _OP_NSUB_2
#define SHR_2						_SHR | _OP_NSUB_2
#define SHL_2						_SHL | _OP_NSUB_2
#define SFL_2						_SFL | _OP_NSUB_2
#define PCK_2						_PCK | _OP_NSUB_2
#define EXT_2						_EXT | _OP_NSUB_2
#define MUL_2						_MUL | _OP_NSUB_2
#define DIV_2						_DIV | _OP_NSUB_2
#define ADDI_2						_ADDI | _OP_NSUB_2
#define SUBI_2						_SUBI | _OP_NSUB_2
#define SHRI_2						_SHRI | _OP_NSUB_2
#define SHLI_2						_SHLI | _OP_NSUB_2
#define MULI_2						_MULI | _OP_NSUB_2
#define DIVI_2						_DIVI | _OP_NSUB_2

#define ADD_4						_ADD | _OP_NSUB_4
#define SUB_4						_SUB | _OP_NSUB_4
#define SHR_4						_SHR | _OP_NSUB_4
#define SHL_4						_SHL | _OP_NSUB_4
#define SFL_4						_SFL | _OP_NSUB_4
#define PCK_4						_PCK | _OP_NSUB_4
#define EXT_4						_EXT | _OP_NSUB_4
#define MUL_4						_MUL | _OP_NSUB_4
#define DIV_4						_DIV | _OP_NSUB_4
#define ADDI_4						_ADDI | _OP_NSUB_4
#define SUBI_4						_SUBI | _OP_NSUB_4
#define SHRI_4						_SHRI | _OP_NSUB_4
#define SHLI_4						_SHLI | _OP_NSUB_4
#define MULI_4						_MULI | _OP_NSUB_4
#define DIVI_4						_DIVI | _OP_NSUB_4

/******************************** PUBLIC ******************************/ 
/*** PUBLIC SIMD types ***/
typedef _UI32						v2x16;
typedef _UI32						v4x8;
typedef _UI32						v2x8;

/*** PUBLIC SIMD Operations ***/
#define ADD_2x16(v1, v2)			_asm1(ADD_2, v1, v2)
#define SUB_2x16(v1, v2)			_asm1(SUB_2, v1, v2)
#define MUL_2x16(v1, v2)			_asm1(MUL_2, v1, v2)
#define DIV_2x16(v1, v2)			_asm1(DIV_2, v1, v2)
#define SHR_2x16(v1, v2)			_asm1(SHR_2, v1, v2)
#define SHL_2x16(v1, v2)			_asm1(SHL_2, v1, v2)
#define ADDI_2x16(v1, imm)			_asm1(ADDI_2, v1, imm)
#define SUBI_2x16(v1, imm)			_asm1(SUBI_2, v1, imm)
#define MULI_2x16(v1, imm)			_asm1(MULI_2, v1, imm)
#define DIVI_2x16(v1, imm)			_asm1(DIVI_2, v1, imm)
#define SHRI_2x16(v1, imm)			_asm1(SHRI_2, v1, imm)
#define SHLI_2x16(v1, imm)			_asm1(SHLI_2, v1, imm)

#define ADD_4x8(v1, v2)				_asm1(ADD_4, v1, v2)
#define SUB_4x8(v1, v2)				_asm1(SUB_4, v1, v2)
#define MUL_4x8(v1, v2)				_asm1(MUL_4, v1, v2)
#define DIV_4x8(v1, v2)				_asm1(DIV_4, v1, v2)
#define SHR_4x8(v1, v2)				_asm1(SHR_4, v1, v2)
#define SHL_4x8(v1, v2)				_asm1(SHL_4, v1, v2)
#define ADDI_4x8(v1, imm)			_asm1(ADDI_4, v1, imm)
#define SUBI_4x8(v1, imm)			_asm1(SUBI_4, v1, imm)
#define MULI_4x8(v1, imm)			_asm1(MULI_4, v1, imm)
#define DIVI_4x8(v1, imm)			_asm1(DIVI_4, v1, imm)
#define SHRI_4x8(v1, imm)			_asm1(SHRI_4, v1, imm)
#define SHLI_4x8(v1, imm)			_asm1(SHLI_4, v1, imm)

#define ADD_2x8(v1, v2)				ADD_4x8(v1, v2)
#define SUB_2x8(v1, v2)				SUB_4x8(v1, v2)
#define MUL_2x8(v1, v2)				MUL_4x8(v1, v2)
#define DIV_2x8(v1, v2)				DIV_4x8(v1, v2)
#define SHR_2x8(v1, v2)				SHR_4x8(v1, v2)
#define SHL_2x8(v1, v2)				SHL_4x8(v1, v2)
#define ADDI_2x8(v1, imm)			ADDI_4x8(v1, imm)
#define SUBI_2x8(v1, imm)			SUBI_4x8(v1, imm)
#define MULI_2x8(v1, imm)			MULI_4x8(v1, imm)
#define DIVI_2x8(v1, imm)			DIVI_4x8(v1, imm)
#define SHRI_2x8(v1, imm)			SHRI_4x8(v1, imm)
#define SHLI_2x8(v1, imm)			SHLI_4x8(v1, imm)

#define PACK_2x16(e0, e1)			_asm1(PCK_2, e0, e1)
#define PACK_4x8(e0, e1, e2, e3)	_asm1(PCK_4, e0, e1, e2, e3)
#define PACK_2x8(e0, e1)			_asm1(PCK_4, 1, 1, e0, e1)

#define EXT_16(v, n)				_asm1(EXT_2, v, n)
#define EXT_8(v ,n)					_asm1(EXT_4, v, n)

#define SFL2_4x8(r3,r2,r1,r0,v1,v2)	_asm1(SFL_4, v1, v2, _SFL_PERM_CODE(r3,r2,r1,r0))
#define SFL2_2x16(r1, r0, v1, v2)	_asm1(SFL_2, v1, v2, _SFL_PERM_CODE(0,0,r1,r0))	

/** Load Operations (cannot be a vex custom operation => use availble ld/st to emulate them) **/
#define LDA_2x16(addr) 	(*((v2x16 *)(addr)))

#define LD_2x16(addr)	\
	(((_UI32)(addr) % sizeof(v2x16)) == 0 ? (*((v2x16 *)(addr))) : PACK_2x16(*((_UI16*)(addr)), *((_UI16*)((addr)+1))))

#define LD_4x8(addr)	\
	(((_UI32)(addr) % sizeof(v4x8)) == 0 ? (*((v4x8 *)(addr))) : PACK_4x8(*((_UI8*)(addr)), *((_UI8*)((addr)+1)), *((_UI8*)((addr)+2)), *((_UI8*)((addr)+3))))


/** Store Operations **/
#define  STA_2x16(addr, v)		(*((v2x16 *)(addr))) = v; 

#define  ST_2x16(addr, v)						\
	if(((_UI32)(addr) % sizeof(v2x16)) == 0) {	\
		*((v2x16 *)(addr)) = v;					\
	} 											\
	else {										\
		*((_UI16*)(addr)) = EXT_16(v, 0);		\
		*((_UI16*)(addr)+1) = EXT_16(v, 1);		\
	}	

/*#define  ST_4x8(addr, v)	(*((v4x8 *)(addr))) = v*/
#define  ST_4x8(addr, v)						\
	if(((_UI32)(addr) % sizeof(v4x8)) == 0) {	\
		*((v4x8 *)(addr)) = v;					\
	} 											\
	else {										\
		*((_UI8*)(addr)) = EXT_8(v, 0);			\
		*((_UI8*)(addr)+1) = EXT_8(v, 1);		\
		*((_UI8*)(addr)+2) = EXT_8(v, 2);		\
		*((_UI8*)(addr)+3) = EXT_8(v, 3);		\
	}	
	

#endif /*_VEX_SIMD_H */
