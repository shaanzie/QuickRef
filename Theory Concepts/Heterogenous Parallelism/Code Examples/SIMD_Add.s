	.file	"SIMD_Add.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%lf"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	xorl	%edi, %edi
	movq	%rsp, %rsi
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	call	clock_gettime@PLT
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	leaq	.LC1(%rip), %rsi
	vxorpd	%xmm1, %xmm1, %xmm1
	movl	$1, %edi
	vxorpd	%xmm0, %xmm0, %xmm0
	vcvtsi2sdq	%rax, %xmm1, %xmm1
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	vcvtsi2sdq	%rax, %xmm0, %xmm0
	vmulsd	.LC0(%rip), %xmm0, %xmm0
	movl	$1, %eax
	vaddsd	%xmm1, %xmm0, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L6
	xorl	%eax, %eax
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	3894859413
	.long	1041313291
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
