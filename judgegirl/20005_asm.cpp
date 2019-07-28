__asm__(R"XX(
    .text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1596:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1596:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.text
	.p2align 4,,15
	.globl	_Z8knapsackjj
	.type	_Z8knapsackjj, @function
_Z8knapsackjj:
.LFB8359:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leaq	dp(%rip), %rcx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movl	$20000004, %edx
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%edi, %ebp
	movl	%esi, %ebx
	movq	%rcx, %rdi
	xorl	%esi, %esi
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	call	memset@PLT
	testl	%ebx, %ebx
	movq	%rax, %rcx
	je	.L4
	movslq	%ebp, %r15
	leal	-1(%rbx), %eax
	leal	4(%rbp), %ebx
	leaq	0(,%r15,4), %rdx
	movdqa	.LC0(%rip), %xmm3
	leaq	4(,%rax,4), %rax
	xorl	%r12d, %r12d
	movl	%ebx, 16(%rsp)
	leaq	-12(%rdx), %rdi
	leaq	(%rcx,%rdx), %rsi
	movq	%rax, (%rsp)
	leaq	(%rcx,%rdi), %r14
	movq	%rsi, 56(%rsp)
	leal	-1(%rbp), %esi
	shrq	$2, %r14
	movl	%esi, 12(%rsp)
	andl	$3, %r14d
	leal	3(%r14), %eax
	movl	%eax, 20(%rsp)
	movl	%r14d, %eax
	negq	%rax
	salq	$2, %rax
	addq	%rax, %rdi
	subq	$12, %rax
	movq	%rax, 24(%rsp)
	movslq	%esi, %rax
	addq	%rcx, %rdi
	movq	%rax, 32(%rsp)
	leal	-2(%rbp), %eax
	movl	%eax, 48(%rsp)
	cltq
	movq	%rax, 40(%rsp)
	leal	-3(%rbp), %eax
	movl	%eax, 52(%rsp)
	.p2align 4,,10
	.p2align 3
.L14:
	leaq	w(%rip), %rax
	movl	(%rax,%r12), %esi
	movl	%ebp, %eax
	subl	%esi, %eax
	js	.L5
	movl	12(%rsp), %r8d
	leal	4(%rax), %edx
	leaq	p(%rip), %rbx
	movl	(%rbx,%r12), %r10d
	movl	%r8d, %r9d
	subl	%esi, %r8d
	cmpl	%ebp, %edx
	setge	%bl
	cmpl	%eax, 16(%rsp)
	leal	2(%r8), %r11d
	setge	%dl
	orb	%dl, %bl
	je	.L6
	cmpl	$7, %r11d
	seta	%bl
	cmpl	$-1, %r8d
	setge	%dl
	testb	%dl, %bl
	je	.L6
	cmpl	$-1, %r8d
	movl	$1, %ebx
	leal	1(%r8), %edx
	cmovl	%ebx, %r11d
	cmpl	$-1, %r8d
	movl	$0, %ebx
	cmovl	%ebx, %edx
	cmpl	20(%rsp), %edx
	jb	.L15
	testl	%r14d, %r14d
	je	.L16
	movslq	%eax, %rdx
	movl	(%rcx,%r15,4), %ebx
	movl	(%rcx,%rdx,4), %eax
	addl	%r10d, %eax
	cmpl	%ebx, %eax
	cmovb	%ebx, %eax
	cmpl	$1, %r14d
	movl	%eax, (%rcx,%r15,4)
	je	.L8
	movq	32(%rsp), %rbx
	movslq	%r8d, %r8
	movl	(%rcx,%r8,4), %eax
	movl	(%rcx,%rbx,4), %r8d
	addl	%r10d, %eax
	cmpl	%r8d, %eax
	cmovb	%r8d, %eax
	movl	48(%rsp), %r8d
	movl	%eax, (%rcx,%rbx,4)
	movl	%r8d, %r9d
	subl	%esi, %r8d
	cmpl	$2, %r14d
	je	.L8
	movq	40(%rsp), %rbx
	movslq	%r8d, %r8
	movl	(%rcx,%r8,4), %eax
	movl	(%rcx,%rbx,4), %r8d
	addl	%r10d, %eax
	cmpl	%r8d, %eax
	cmovb	%r8d, %eax
	movl	52(%rsp), %r8d
	movl	%eax, (%rcx,%rbx,4)
	movl	%r8d, %r9d
	subl	%esi, %r8d
.L8:
	movq	24(%rsp), %rax
	movl	%r10d, 8(%rsp)
	subl	%r14d, %r11d
	movd	8(%rsp), %xmm7
	movl	%r11d, %r13d
	shrl	$2, %r13d
	leaq	(%rax,%rdx,4), %rbx
	pshufd	$0, %xmm7, %xmm5
	xorl	%eax, %eax
	xorl	%edx, %edx
	addq	%rcx, %rbx
	.p2align 4,,10
	.p2align 3
.L10:
	movdqu	(%rbx,%rax), %xmm6
	pshufd	$27, (%rdi,%rax), %xmm2
	addl	$1, %edx
	pshufd	$27, %xmm6, %xmm1
	movdqa	%xmm2, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	%xmm1, %xmm0
	psubd	%xmm3, %xmm4
	psubd	%xmm3, %xmm0
	pcmpgtd	%xmm4, %xmm0
	pand	%xmm0, %xmm1
	pandn	%xmm2, %xmm0
	por	%xmm1, %xmm0
	pshufd	$27, %xmm0, %xmm0
	movaps	%xmm0, (%rdi,%rax)
	subq	$16, %rax
	cmpl	%edx, %r13d
	ja	.L10
	movl	%r11d, %edx
	movl	%r8d, %eax
	andl	$-4, %edx
	subl	%edx, %eax
	subl	%edx, %r9d
	cmpl	%edx, %r11d
	je	.L5
.L7:
	cltq
	movslq	%r9d, %rdx
	movl	(%rcx,%rax,4), %ebx
	movl	(%rcx,%rdx,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %eax
	cmovb	%r8d, %eax
	movl	%eax, (%rcx,%rdx,4)
	leal	-1(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L5
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-2(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L5
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-3(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L5
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-4(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L5
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	subl	$5, %r9d
	movl	%edx, (%rcx,%rax,4)
	movl	%r9d, %eax
	subl	%esi, %eax
	js	.L5
	cltq
	movslq	%r9d, %r9
	addl	(%rcx,%rax,4), %r10d
	movl	(%rcx,%r9,4), %eax
	cmpl	%eax, %r10d
	cmovb	%eax, %r10d
	movl	%r10d, (%rcx,%r9,4)
.L5:
	addq	$4, %r12
	cmpq	(%rsp), %r12
	jne	.L14
.L4:
	movl	%ebp, %ebp
	movl	(%rcx,%rbp,4), %eax
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore_state
	movslq	%eax, %rdx
	movq	56(%rsp), %r9
	movq	%rdx, %rax
	movq	%rdx, %r11
	subq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%r9,%rax,4), %edx
	movl	(%r9), %esi
	addl	%r10d, %edx
	cmpl	%esi, %edx
	cmovb	%esi, %edx
	subl	$1, %r11d
	subq	$4, %r9
	movl	%edx, 4(%r9)
	cmpl	$-1, %r11d
	jne	.L13
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L16:
	movslq	%eax, %rdx
	movl	%ebp, %r9d
	movq	%rdx, %r8
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L15:
	movl	%ebp, %r9d
	jmp	.L7
	.cfi_endproc
.LFE8359:
	.size	_Z8knapsackjj, .-_Z8knapsackjj
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB8360:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	xorl	%edi, %edi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$120, %rsp
	.cfi_def_cfa_offset 176
	movq	%fs:40, %rax
	movq	%rax, 104(%rsp)
	xorl	%eax, %eax
	call	_ZNSt8ios_base15sync_with_stdioEb@PLT
	leaq	96(%rsp), %rax
	movdqa	.LC0(%rip), %xmm3
	movq	$0, 232+_ZSt3cin(%rip)
	movq	%rax, 80(%rsp)
	leaq	100(%rsp), %rax
	movq	%rax, 88(%rsp)
	.p2align 4,,10
	.p2align 3
.L56:
	movq	80(%rsp), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	movaps	%xmm3, (%rsp)
	call	_ZNSi10_M_extractIjEERSiRT_@PLT
	movq	%rax, %rdi
	movq	88(%rsp), %rsi
	call	_ZNSi10_M_extractIjEERSiRT_@PLT
	movq	(%rax), %rdx
	movq	-24(%rdx), %rdx
	testb	$5, 32(%rax,%rdx)
	jne	.L39
	movl	100(%rsp), %eax
	movdqa	(%rsp), %xmm3
	testl	%eax, %eax
	je	.L40
	leaq	p(%rip), %r12
	leaq	w(%rip), %rbp
	leaq	_ZSt3cin(%rip), %r13
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L41:
	movq	%r12, %rsi
	movq	%r13, %rdi
	addl	$1, %ebx
	movaps	%xmm3, (%rsp)
	call	_ZNSirsERi@PLT
	movq	%rbp, %rsi
	movq	%rax, %rdi
	addq	$4, %r12
	call	_ZNSirsERi@PLT
	movl	100(%rsp), %r14d
	addq	$4, %rbp
	movdqa	(%rsp), %xmm3
	cmpl	%r14d, %ebx
	jb	.L41
	leaq	dp(%rip), %rcx
	xorl	%esi, %esi
	movl	$20000004, %edx
	movl	96(%rsp), %ebp
	movq	%rcx, %rdi
	call	memset@PLT
	testl	%r14d, %r14d
	movq	%rax, %rcx
	movdqa	(%rsp), %xmm3
	je	.L42
	movslq	%ebp, %r15
	leal	-1(%r14), %eax
	leal	4(%rbp), %ebx
	leaq	0(,%r15,4), %rdx
	xorl	%r12d, %r12d
	leaq	4(,%rax,4), %rax
	movl	%ebx, 32(%rsp)
	leaq	-12(%rdx), %rdi
	leaq	(%rcx,%rdx), %rsi
	movq	%rax, 16(%rsp)
	leaq	(%rcx,%rdi), %r14
	movq	%rsi, 72(%rsp)
	leal	-1(%rbp), %esi
	shrq	$2, %r14
	movl	%esi, 28(%rsp)
	andl	$3, %r14d
	leal	3(%r14), %eax
	movl	%eax, 36(%rsp)
	movl	%r14d, %eax
	negq	%rax
	salq	$2, %rax
	addq	%rax, %rdi
	subq	$12, %rax
	movq	%rax, 40(%rsp)
	movslq	%esi, %rax
	addq	%rcx, %rdi
	movq	%rax, 48(%rsp)
	leal	-2(%rbp), %eax
	movl	%eax, 64(%rsp)
	cltq
	movq	%rax, 56(%rsp)
	leal	-3(%rbp), %eax
	movl	%eax, 68(%rsp)
	.p2align 4,,10
	.p2align 3
.L52:
	leaq	w(%rip), %rax
	movl	(%rax,%r12), %esi
	movl	%ebp, %eax
	subl	%esi, %eax
	js	.L43
	movl	28(%rsp), %r8d
	leal	4(%rax), %edx
	leaq	p(%rip), %rbx
	movl	(%rbx,%r12), %r10d
	movl	%r8d, %r9d
	subl	%esi, %r8d
	cmpl	%ebp, %edx
	setge	%bl
	cmpl	32(%rsp), %eax
	leal	2(%r8), %r11d
	setle	%dl
	orb	%dl, %bl
	je	.L44
	cmpl	$7, %r11d
	seta	%bl
	cmpl	$-1, %r8d
	setge	%dl
	testb	%dl, %bl
	je	.L44
	cmpl	$-1, %r8d
	movl	$1, %ebx
	leal	1(%r8), %edx
	cmovl	%ebx, %r11d
	cmpl	$-1, %r8d
	movl	$0, %ebx
	cmovl	%ebx, %edx
	cmpl	36(%rsp), %edx
	jb	.L58
	testl	%r14d, %r14d
	movslq	%eax, %rdx
	je	.L59
	movl	(%rcx,%rdx,4), %eax
	movl	(%rcx,%r15,4), %ebx
	addl	%r10d, %eax
	cmpl	%ebx, %eax
	cmovb	%ebx, %eax
	cmpl	$1, %r14d
	movl	%eax, (%rcx,%r15,4)
	je	.L46
	movq	48(%rsp), %rbx
	movslq	%r8d, %r8
	movl	(%rcx,%r8,4), %eax
	movl	(%rcx,%rbx,4), %r8d
	addl	%r10d, %eax
	cmpl	%r8d, %eax
	cmovb	%r8d, %eax
	movl	64(%rsp), %r8d
	movl	%eax, (%rcx,%rbx,4)
	movl	%r8d, %r9d
	subl	%esi, %r8d
	cmpl	$2, %r14d
	je	.L46
	movq	56(%rsp), %rbx
	movslq	%r8d, %r8
	movl	(%rcx,%r8,4), %eax
	movl	(%rcx,%rbx,4), %r8d
	addl	%r10d, %eax
	cmpl	%r8d, %eax
	cmovb	%r8d, %eax
	movl	68(%rsp), %r8d
	movl	%eax, (%rcx,%rbx,4)
	movl	%r8d, %r9d
	subl	%esi, %r8d
.L46:
	movq	40(%rsp), %rax
	movl	%r10d, (%rsp)
	subl	%r14d, %r11d
	movd	(%rsp), %xmm7
	movl	%r11d, %r13d
	shrl	$2, %r13d
	leaq	(%rax,%rdx,4), %rbx
	pshufd	$0, %xmm7, %xmm5
	xorl	%eax, %eax
	xorl	%edx, %edx
	addq	%rcx, %rbx
	.p2align 4,,10
	.p2align 3
.L48:
	movdqu	(%rbx,%rax), %xmm6
	pshufd	$27, (%rdi,%rax), %xmm2
	addl	$1, %edx
	pshufd	$27, %xmm6, %xmm1
	movdqa	%xmm2, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	%xmm1, %xmm0
	psubd	%xmm3, %xmm4
	psubd	%xmm3, %xmm0
	pcmpgtd	%xmm4, %xmm0
	pand	%xmm0, %xmm1
	pandn	%xmm2, %xmm0
	por	%xmm1, %xmm0
	pshufd	$27, %xmm0, %xmm0
	movaps	%xmm0, (%rdi,%rax)
	subq	$16, %rax
	cmpl	%edx, %r13d
	ja	.L48
	movl	%r11d, %edx
	movl	%r8d, %eax
	andl	$-4, %edx
	subl	%edx, %r9d
	subl	%edx, %eax
	cmpl	%edx, %r11d
	je	.L43
.L45:
	cltq
	movslq	%r9d, %rdx
	movl	(%rcx,%rax,4), %ebx
	movl	(%rcx,%rdx,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %eax
	cmovb	%r8d, %eax
	movl	%eax, (%rcx,%rdx,4)
	leal	-1(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L43
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-2(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L43
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-3(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L43
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	movl	%edx, (%rcx,%rax,4)
	leal	-4(%r9), %eax
	movl	%eax, %edx
	subl	%esi, %edx
	js	.L43
	movslq	%edx, %rdx
	cltq
	movl	(%rcx,%rdx,4), %ebx
	movl	(%rcx,%rax,4), %r8d
	addl	%r10d, %ebx
	cmpl	%r8d, %ebx
	movl	%ebx, %edx
	cmovb	%r8d, %edx
	subl	$5, %r9d
	movl	%edx, (%rcx,%rax,4)
	movl	%r9d, %eax
	subl	%esi, %eax
	js	.L43
	cltq
	movslq	%r9d, %r9
	addl	(%rcx,%rax,4), %r10d
	movl	(%rcx,%r9,4), %eax
	cmpl	%eax, %r10d
	cmovb	%eax, %r10d
	movl	%r10d, (%rcx,%r9,4)
.L43:
	addq	$4, %r12
	cmpq	16(%rsp), %r12
	jne	.L52
.L42:
	movl	%ebp, %ebp
	leaq	_ZSt4cout(%rip), %rdi
	movl	(%rcx,%rbp,4), %esi
	movaps	%xmm3, (%rsp)
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movdqa	(%rsp), %xmm3
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L84
	cmpb	$0, 56(%rbx)
	je	.L54
	movsbl	67(%rbx), %esi
.L55:
	movq	%rbp, %rdi
	movaps	%xmm3, (%rsp)
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movdqa	(%rsp), %xmm3
	jmp	.L56
	.p2align 4,,10
	.p2align 3
.L44:
	movslq	%eax, %rdx
	movq	72(%rsp), %r9
	movq	%rdx, %rax
	movq	%rdx, %r11
	subq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L51:
	movl	(%r9,%rax,4), %edx
	movl	(%r9), %esi
	addl	%r10d, %edx
	cmpl	%esi, %edx
	cmovb	%esi, %edx
	subl	$1, %r11d
	subq	$4, %r9
	movl	%edx, 4(%r9)
	cmpl	$-1, %r11d
	jne	.L51
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L59:
	movq	%rdx, %r8
	movl	%ebp, %r9d
	jmp	.L46
	.p2align 4,,10
	.p2align 3
.L58:
	movl	%ebp, %r9d
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L54:
	movq	%rbx, %rdi
	movaps	%xmm3, (%rsp)
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movl	$10, %esi
	movq	(%rbx), %rax
	movdqa	(%rsp), %xmm3
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L55
	movq	%rbx, %rdi
	call	*%rax
	movdqa	(%rsp), %xmm3
	movsbl	%al, %esi
	jmp	.L55
.L39:
	xorl	%eax, %eax
	movq	104(%rsp), %rdi
	xorq	%fs:40, %rdi
	jne	.L85
	addq	$120, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L40:
	.cfi_restore_state
	leaq	dp(%rip), %rdi
	movl	$20000004, %edx
	xorl	%esi, %esi
	movaps	%xmm3, (%rsp)
	movl	96(%rsp), %ebp
	call	memset@PLT
	leaq	dp(%rip), %rcx
	movdqa	(%rsp), %xmm3
	jmp	.L42
.L84:
	call	_ZSt16__throw_bad_castv@PLT
.L85:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE8360:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_p, @function
_GLOBAL__sub_I_p:
.LFB9653:
	.cfi_startproc
	leaq	_ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE9653:
	.size	_GLOBAL__sub_I_p, .-_GLOBAL__sub_I_p
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_p
	.globl	dp
	.bss
	.align 32
	.type	dp, @object
	.size	dp, 20000004
dp:
	.zero	20000004
	.globl	w
	.align 32
	.type	w, @object
	.size	w, 4096
w:
	.zero	4096
	.globl	p
	.align 32
	.type	p, @object
	.size	p, 4096
p:
	.zero	4096
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
)XX");
