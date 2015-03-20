#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "vex_simd.h"


#define _DEBUG 		0

#if _DEBUG
	#define _debug_print(format, ...)	_linux_fprintf(stdout, format, __VA_ARGS__);
#else
	#define _debug_print(format, ...)	
#endif /* DEBUG */
		
#define _xSTR(a)		#a
#define _STR(a)			_xSTR(a)


#define _EXEC_ARITH_2(op, s1, s2) { 			\
	_UI16 re1, re0;								\
	re1 = _EXT32_16(s1,1) op _EXT32_16(s2,1); 	\
	re0 = _EXT32_16(s1,0) op _EXT32_16(s2,0); 	\
	_debug_print("\n%5d %s %5d = %5d\n%5d %s %5d = %5d\n", _EXT32_16(s1,1),_STR(op),_EXT32_16(s2,1),re1,  _EXT32_16(s1,0),_STR(op),_EXT32_16(s2,0),re0);\
	return _PACK32_16(re0, re1);				\
}

#define _EXEC_ARITHI_2(op, s1, s2) { 			\
	_UI16 re1, re0;								\
	re1 = _EXT32_16(s1,1) op ((_UI16)s2); 	\
	re0 = _EXT32_16(s1,0) op ((_UI16)s2); 	\
	_debug_print("\n%5d %s %5d = %5d\n%5d %s %5d = %5d\n", _EXT32_16(s1,1),_STR(op),((_UI16)s2),re1,  _EXT32_16(s1,0),_STR(op),((_UI16)s2),re0);\
	return _PACK32_16(re0, re1);				\
}
	
#define _EXEC_ARITH_4(op, s1, s2) { 			\
	_UI8 re3, re2, re1, re0; 					\
	re3 = _EXT32_8(s1,3) op _EXT32_8(s2,3); 	\
	re2 = _EXT32_8(s1,2) op _EXT32_8(s2,2); 	\
	re1 = _EXT32_8(s1,1) op _EXT32_8(s2,1); 	\
	re0 = _EXT32_8(s1,0) op _EXT32_8(s2,0); 	\
	_debug_print("\n%3d %s %3d = %3d\n%3d %s %3d = %3d\n%3d %s %d3 = %3d\n%3d %s %3d = %3d\n", _EXT32_8(s1,3),_STR(op),_EXT32_8(s2,3),re3, _EXT32_8(s1,2),_STR(op),_EXT32_8(s2,2),re2, _EXT32_8(s1,1),_STR(op),_EXT32_8(s2,1),re1, _EXT32_8(s1,0),_STR(op),_EXT32_8(s2,0),re0); \
	return _PACK32_8(re0, re1, re2, re3); 		\
}

#define _EXEC_ARITHI_4(op, s1, s2) { 			\
	_UI8 re3, re2, re1, re0; 					\
	re3 = _EXT32_8(s1,3) op ((_UI8)s2); 		\
	re2 = _EXT32_8(s1,2) op ((_UI8)s2); 	 	\
	re1 = _EXT32_8(s1,1) op ((_UI8)s2); 	 	\
	re0 = _EXT32_8(s1,0) op ((_UI8)s2); 	 	\
	_debug_print("\n%3d %s %3d = %3d\n%d %s %3d = %3d\n%3d %s %3d = %3d\n%3d %s %3d = %3d\n", _EXT32_8(s1,3),_STR(op),((_UI8)s2),re3, _EXT32_8(s1,2),_STR(op),((_UI8)s2),re2, _EXT32_8(s1,1),_STR(op),((_UI8)s2),re1, _EXT32_8(s1,0),_STR(op),((_UI8)s2),re0); \
	return _PACK32_8(re0, re1, re2, re3); 		\
}

#define _EXEC_SFL_4to1(sflperm, subn, r, s3,s2,s1,s0) 	\
	switch(_GET_SFL_SUB(sflperm, subn)) {				\
	case SFL_SRC0:		\
		r = s0;	break;	\
	case SFL_SRC1:		\
		r = s1;	break;	\
	case SFL_SRC2:		\
		r = s2;	break;	\
	case SFL_SRC3:		\
		r = s3;	break;	\
	default:			\
		_linux_fprintf(stderr, "Error: shiffle opcode %d not supported\n", opcode);	\
		_linux_exit(1);	\
	}
		
#define _EXEC_SFL_8to1(sflperm, subn, r, s7,s6,s5,s4,s3,s2,s1,s0) \
	switch(_GET_SFL_SUB(sflperm, subn)) {	\
	case SFL_SRC0:		\
		r = s0;	break;	\
	case SFL_SRC1:		\
		r = s1;	break;	\
	case SFL_SRC2:		\
		r = s2;	break;	\
	case SFL_SRC3:		\
		r = s3;	break;	\
	case SFL_SRC4:		\
		r = s4;	break;	\
	case SFL_SRC5:		\
		r = s5;	break;	\
	case SFL_SRC6:		\
		r = s6;	break;	\
	case SFL_SRC7:		\
		r = s7;	break;	\
	default:			\
		_linux_fprintf(stderr, "Error: shiffle opcode %d not supported\n", opcode);	\
		_linux_exit(1);	\
	}
		
#define _EXEC_SFL_2(sflperm, s1, s2) {		\
	_UI16 re1, re0;							\
	_EXEC_SFL_4to1(sflperm, 1, re1, _EXT32_16(s1,1),_EXT32_16(s1,0),_EXT32_16(s2,1),_EXT32_16(s2,0)) \
	_EXEC_SFL_4to1(sflperm, 0, re0, _EXT32_16(s1,1),_EXT32_16(s1,0),_EXT32_16(s2,1),_EXT32_16(s2,0)) \
	_debug_print("\nSHUFFLE_2x16 select(%d,%d): %d,%d %d,%d => %d,%d\n", _GET_SFL_SUB(sflperm,1), _GET_SFL_SUB(sflperm,0), _EXT32_16(s1,1),_EXT32_16(s1,0),_EXT32_16(s2,1),_EXT32_16(s2,0), re1,re0); \
	return _PACK32_16(re0, re1);			\
}

#define _EXEC_SFL_4(sflperm, s1, s2) {		\
	_UI8 re3, re2, re1, re0;				\
	_EXEC_SFL_8to1(sflperm, 3, re3, _EXT32_8(s1,3),_EXT32_8(s1,2),_EXT32_8(s1,1),_EXT32_8(s1,0), _EXT32_8(s2,3),_EXT32_8(s2,2),_EXT32_8(s2,1),_EXT32_8(s2,0)) \
	_EXEC_SFL_8to1(sflperm, 2, re2, _EXT32_8(s1,3),_EXT32_8(s1,2),_EXT32_8(s1,1),_EXT32_8(s1,0), _EXT32_8(s2,3),_EXT32_8(s2,2),_EXT32_8(s2,1),_EXT32_8(s2,0)) \
	_EXEC_SFL_8to1(sflperm, 1, re1, _EXT32_8(s1,3),_EXT32_8(s1,2),_EXT32_8(s1,1),_EXT32_8(s1,0), _EXT32_8(s2,3),_EXT32_8(s2,2),_EXT32_8(s2,1),_EXT32_8(s2,0)) \
	_EXEC_SFL_8to1(sflperm, 0, re0, _EXT32_8(s1,3),_EXT32_8(s1,2),_EXT32_8(s1,1),_EXT32_8(s1,0), _EXT32_8(s2,3),_EXT32_8(s2,2),_EXT32_8(s2,1),_EXT32_8(s2,0)) \
	_debug_print("\nSHUFFLE_4x8 select(%d,%d,%d,%d): %d,%d,%d,%d, %d,%d,%d,%d => %d,%d,%d,%d\n", _GET_SFL_SUB(sflperm,3), _GET_SFL_SUB(sflperm,2), _GET_SFL_SUB(sflperm,1), _GET_SFL_SUB(sflperm,0), _EXT32_8(s1,3),_EXT32_8(s1,2),_EXT32_8(s1,1),_EXT32_8(s1,0), _EXT32_8(s2,3),_EXT32_8(s2,2),_EXT32_8(s2,1),_EXT32_8(s2,0), re3,re2,re1,re0); \
	return _PACK32_8(re0, re1, re2, re3);	\
}	
	
/*** EXEC MACROS ***/	
#define _EXEC_ARITH(n, op, s1, s2) 			\
	if(n == _OP_NSUB_2)						\
		_EXEC_ARITH_2(op, s1, s2)			\
	else if (n == _OP_NSUB_4)				\
		_EXEC_ARITH_4(op, s1, s2)	
		
#define _EXEC_ARITHI(n, op, s1, s2) 		\
	if(n == _OP_NSUB_2)						\
		_EXEC_ARITHI_2(op, s1, s2)			\
	else if (n == _OP_NSUB_4)				\
		_EXEC_ARITHI_4(op, s1, s2)	

#define _EXEC_SHUFFLE(n, sflperm, s1, s2)	\
	if(n == _OP_NSUB_2)						\
		_EXEC_SFL_2(sflperm, s1, s2)		\
	else if (n == _OP_NSUB_4)				\
		_EXEC_SFL_4(sflperm, s1, s2)	

#define _EXEC_EXT(n, v, ne)					\
	if(n == _OP_NSUB_2)						\
		return _EXT32_16(v, ne);			\
	else if(n == _OP_NSUB_4)				\
		return _EXT32_8(v, ne);				

#define _EXEC_PCK_2(e0, e1)					\
	return _PACK32_16(e0, e1);

#define _EXEC_PCK_4(e0, e1, e2, e3)			\
	return _PACK32_8(e0, e1, e2, e3);
	
/**********************************************************************/

typedef unsigned int                       __vexasm1;

extern __vexasm1 sim_asm_op1(unsigned int opcode, ...)
{
    va_list ap;
    unsigned int s1, s2, s3, s4;
	
    va_start(ap, opcode);
    s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);

	switch (_GET_OP(opcode)) {
	/* arith 2 registers */
	case _ADD:	
		_EXEC_ARITH(_GET_NSUB(opcode), +, s1, s2)
		break;
	case _SUB:
		_EXEC_ARITH(_GET_NSUB(opcode), -, s1, s2)
		break;
	case _SHL:
		_EXEC_ARITH(_GET_NSUB(opcode), <<, s1, s2)
		break;
	case _SHR:
		_EXEC_ARITH(_GET_NSUB(opcode), >>, s1, s2)
		break;
	case _MUL:
		_EXEC_ARITH(_GET_NSUB(opcode), *, s1, s2)
		break;
	case _DIV:
		_EXEC_ARITH(_GET_NSUB(opcode), /, s1, s2)
		break;
	/* arith reg imm: (s1=reg, s2=imm) */
	case _ADDI:	
		_EXEC_ARITHI(_GET_NSUB(opcode), +, s1, s2)
		break;
	case _SUBI:
		_EXEC_ARITHI(_GET_NSUB(opcode), -, s1, s2)
		break;
	case _SHLI:
		_EXEC_ARITHI(_GET_NSUB(opcode), <<, s1, s2)
		break;
	case _SHRI:
		_EXEC_ARITHI(_GET_NSUB(opcode), >>, s1, s2)
		break;
	case _MULI:
		_EXEC_ARITHI(_GET_NSUB(opcode), *, s1, s2)
		break;
	case _DIVI:
		_EXEC_ARITHI(_GET_NSUB(opcode), /, s1, s2)
		break;
	case _SPROD:
		{
			if(_GET_NSUB(opcode) == _OP_NSUB_2)		{
				_UI8 re3, re2, re1, re0; 					\
				return  _EXT32_8(s1,3) * _EXT32_8(s2,3)+
				 _EXT32_8(s1,2) * _EXT32_8(s2,2)+
				  _EXT32_8(s1,1) * _EXT32_8(s2,1)+
				  _EXT32_8(s1,0) * _EXT32_8(s2,0);
				//_debug_print("\n%3d %s %3d = %3d\n%3d %s %3d = %3d\n%3d %s %d3 = %3d\n%3d %s %3d = %3d\n", _EXT32_8(s1,3),_STR(op),_EXT32_8(s2,3),re3, _EXT32_8(s1,2),_STR(op),_EXT32_8(s2,2),re2, _EXT32_8(s1,1),_STR(op),_EXT32_8(s2,1),re1, _EXT32_8(s1,0),_STR(op),_EXT32_8(s2,0),re0); \
				return _PACK32_8(re0, re1, re2, re3); 		\
return ()
			} else if (_GET_NSUB(opcode) == _OP_NSUB_4)	{
									\
				return  _EXT32_16(s1,1) * _EXT32_16(s2,1)+
						_EXT32_16(s1,0) * _EXT32_16(s2,0);
			}
			break;
		}
	/* Shuffling: (s1=vector1(MS), s2=vector0(LS), s3=permutation */
	case _SFL:
		s3 = va_arg(ap, unsigned int);
		_EXEC_SHUFFLE(_GET_NSUB(opcode),s3, s1, s2)
		break;
	/* Packing: (s1=sub0(LS), s2=sub1(MS)) */
	case _PCK:
		if(_isOP_2(opcode))
			_EXEC_PCK_2(s1,s2)
		else if(_isOP_4(opcode)) {
			s3 = va_arg(ap, unsigned int);
			s4 = va_arg(ap, unsigned int);
			_EXEC_PCK_4(s1,s2,s3,s4)
		}
		break;
	/* Extract: (s1=vector, s2=sub_n) */
	case _EXT:
		_EXEC_EXT(_GET_NSUB(opcode), s1, s2)
		break;
	default:
		_linux_fprintf(stderr, "Error1: SIMD opcode '%d' is not supported\n", opcode);
		_linux_exit(1);
	}
	
	_linux_fprintf(stderr, "Error2: SIMD opcode '%d' is not supported\n", opcode);
	_linux_exit(2);
}



