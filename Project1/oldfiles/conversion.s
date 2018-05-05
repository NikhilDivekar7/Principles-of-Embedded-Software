	.file	"conversion.c"
	.text
.Ltext0:
	.globl	my_itoa
	.type	my_itoa, @function
my_itoa:
.LFB0:
	.file 1 "conversion.c"
	.loc 1 18 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	.loc 1 20 0
	movl	$0, -12(%ebp)
	.loc 1 21 0
	movl	$0, -8(%ebp)
	.loc 1 22 0
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	.loc 1 24 0 discriminator 3
	addl	$1, 12(%ebp)
	.loc 1 22 0 discriminator 3
	addl	$1, -12(%ebp)
.L2:
	.loc 1 22 0 is_stmt 0 discriminator 1
	cmpl	$99, -12(%ebp)
	jle	.L3
	.loc 1 28 0 is_stmt 1
	cmpl	$0, 8(%ebp)
	jle	.L4
	.loc 1 30 0
	jmp	.L5
.L8:
	.loc 1 32 0
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	%eax, -4(%ebp)
	.loc 1 33 0
	cmpl	$9, -4(%ebp)
	jg	.L6
	.loc 1 34 0
	movl	-4(%ebp), %eax
	addl	$48, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	jmp	.L7
.L6:
	.loc 1 36 0
	movl	-4(%ebp), %eax
	addl	$55, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
.L7:
	.loc 1 38 0
	subl	$1, 12(%ebp)
	.loc 1 39 0
	addl	$1, -8(%ebp)
	.loc 1 40 0
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%eax, 8(%ebp)
.L5:
	.loc 1 30 0
	cmpl	$0, 8(%ebp)
	jne	.L8
	jmp	.L9
.L4:
	.loc 1 47 0
	cmpl	$0, 8(%ebp)
	jns	.L9
	.loc 1 49 0
	negl	8(%ebp)
	.loc 1 50 0
	jmp	.L10
.L13:
	.loc 1 52 0
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	%eax, -4(%ebp)
	.loc 1 53 0
	cmpl	$9, -4(%ebp)
	jg	.L11
	.loc 1 54 0
	movl	-4(%ebp), %eax
	addl	$48, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	jmp	.L12
.L11:
	.loc 1 56 0
	movl	-4(%ebp), %eax
	addl	$55, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
.L12:
	.loc 1 58 0
	subl	$1, 12(%ebp)
	.loc 1 59 0
	addl	$1, -8(%ebp)
	.loc 1 60 0
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%eax, 8(%ebp)
.L10:
	.loc 1 50 0
	cmpl	$0, 8(%ebp)
	jne	.L13
	.loc 1 62 0
	movl	12(%ebp), %eax
	movb	$45, (%eax)
	.loc 1 63 0
	subl	$1, 12(%ebp)
	.loc 1 64 0
	addl	$1, -8(%ebp)
.L9:
	.loc 1 67 0
	movl	-8(%ebp), %eax
	.loc 1 68 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	my_itoa, .-my_itoa
	.globl	my_atoi
	.type	my_atoi, @function
my_atoi:
.LFB1:
	.loc 1 71 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	12(%ebp), %eax
	movb	%al, -20(%ebp)
	.loc 1 72 0
	movl	$0, -8(%ebp)
	.loc 1 73 0
	movl	$0, -4(%ebp)
	.loc 1 74 0
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$45, %al
	jne	.L17
	.loc 1 76 0
	movl	$1, -4(%ebp)
	.loc 1 77 0
	addl	$1, 8(%ebp)
	.loc 1 79 0
	jmp	.L17
.L23:
	.loc 1 81 0
	movl	-8(%ebp), %eax
	imull	16(%ebp), %eax
	movl	%eax, -8(%ebp)
	.loc 1 82 0
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$65, %al
	je	.L18
	.loc 1 82 0 is_stmt 0 discriminator 1
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$66, %al
	je	.L18
	.loc 1 82 0 discriminator 2
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$67, %al
	je	.L18
	.loc 1 82 0 discriminator 3
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$68, %al
	je	.L18
	.loc 1 82 0 discriminator 4
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$69, %al
	je	.L18
	.loc 1 82 0 discriminator 5
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$70, %al
	jne	.L19
.L18:
	.loc 1 84 0 is_stmt 1
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	subl	$55, %eax
	movl	%eax, -8(%ebp)
	jmp	.L20
.L19:
	.loc 1 86 0
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$97, %al
	je	.L21
	.loc 1 86 0 is_stmt 0 discriminator 1
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$98, %al
	je	.L21
	.loc 1 86 0 discriminator 2
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$99, %al
	je	.L21
	.loc 1 86 0 discriminator 3
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$100, %al
	je	.L21
	.loc 1 86 0 discriminator 4
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$101, %al
	je	.L21
	.loc 1 86 0 discriminator 5
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$102, %al
	jne	.L22
.L21:
	.loc 1 88 0 is_stmt 1
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	subl	$87, %eax
	movl	%eax, -8(%ebp)
	jmp	.L20
.L22:
	.loc 1 92 0
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	subl	$48, %eax
	movl	%eax, -8(%ebp)
.L20:
	.loc 1 94 0
	addl	$1, 8(%ebp)
.L17:
	.loc 1 79 0
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L23
	.loc 1 96 0
	cmpl	$1, -4(%ebp)
	jne	.L24
	.loc 1 98 0
	negl	-8(%ebp)
.L24:
	.loc 1 100 0
	movl	-8(%ebp), %eax
	.loc 1 101 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_atoi, .-my_atoi
	.section	.rodata
.LC0:
	.string	"There is an error."
	.text
	.globl	big_to_little32
	.type	big_to_little32, @function
big_to_little32:
.LFB2:
	.loc 1 105 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	.loc 1 110 0
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	.loc 1 111 0
	cmpl	$0, 12(%ebp)
	je	.L27
	.loc 1 111 0 is_stmt 0 discriminator 1
	cmpl	$0, 8(%ebp)
	jne	.L28
.L27:
	.loc 1 113 0 is_stmt 1
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	.loc 1 114 0
	movl	$1, %eax
	jmp	.L29
.L28:
	.loc 1 116 0
	movl	$0, -16(%ebp)
	jmp	.L30
.L31:
	.loc 1 118 0
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	.loc 1 119 0
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	leal	3(%eax), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 120 0
	movl	-16(%ebp), %eax
	leal	3(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 122 0
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	.loc 1 123 0
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	leal	2(%eax), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 124 0
	movl	-16(%ebp), %eax
	leal	2(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 126 0
	addl	$4, -16(%ebp)
.L30:
	.loc 1 116 0 discriminator 1
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L31
	.loc 1 128 0
	movl	$0, %eax
.L29:
	.loc 1 129 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	big_to_little32, .-big_to_little32
	.globl	little_to_big32
	.type	little_to_big32, @function
little_to_big32:
.LFB3:
	.loc 1 132 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	.loc 1 137 0
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	.loc 1 138 0
	cmpl	$0, 12(%ebp)
	je	.L33
	.loc 1 138 0 is_stmt 0 discriminator 1
	cmpl	$0, 8(%ebp)
	jne	.L34
.L33:
	.loc 1 140 0 is_stmt 1
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	.loc 1 141 0
	movl	$1, %eax
	jmp	.L35
.L34:
	.loc 1 143 0
	movl	$0, -16(%ebp)
	jmp	.L36
.L37:
	.loc 1 145 0
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	.loc 1 146 0
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	leal	3(%eax), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 147 0
	movl	-16(%ebp), %eax
	leal	3(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 149 0
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	.loc 1 150 0
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	leal	2(%eax), %ecx
	movl	-12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 151 0
	movl	-16(%ebp), %eax
	leal	2(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 153 0
	addl	$4, -16(%ebp)
.L36:
	.loc 1 143 0 discriminator 1
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L37
	.loc 1 155 0
	movl	$0, %eax
.L35:
	.loc 1 156 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	little_to_big32, .-little_to_big32
.Letext0:
	.file 2 "/usr/include/stdint.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x23a
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF27
	.byte	0xc
	.long	.LASF28
	.long	.LASF29
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.long	.LASF8
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF9
	.uleb128 0x4
	.byte	0x4
	.long	0x78
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF10
	.uleb128 0x5
	.long	.LASF11
	.byte	0x2
	.byte	0x24
	.long	0x41
	.uleb128 0x5
	.long	.LASF12
	.byte	0x2
	.byte	0x26
	.long	0x4f
	.uleb128 0x5
	.long	.LASF13
	.byte	0x2
	.byte	0x30
	.long	0x2c
	.uleb128 0x5
	.long	.LASF14
	.byte	0x2
	.byte	0x33
	.long	0x25
	.uleb128 0x6
	.long	.LASF18
	.byte	0x1
	.byte	0x11
	.long	0x95
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x115
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x11
	.long	0x8a
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x8
	.string	"ptr"
	.byte	0x1
	.byte	0x11
	.long	0x72
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.long	.LASF16
	.byte	0x1
	.byte	0x11
	.long	0xa0
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x9
	.string	"r"
	.byte	0x1
	.byte	0x13
	.long	0x8a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x14
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xa
	.long	.LASF17
	.byte	0x1
	.byte	0x15
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x6
	.long	.LASF19
	.byte	0x1
	.byte	0x46
	.long	0x8a
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x175
	.uleb128 0x8
	.string	"ptr"
	.byte	0x1
	.byte	0x46
	.long	0x175
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF20
	.byte	0x1
	.byte	0x46
	.long	0x95
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x7
	.long	.LASF16
	.byte	0x1
	.byte	0x46
	.long	0xa0
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xa
	.long	.LASF21
	.byte	0x1
	.byte	0x48
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0xa
	.long	.LASF22
	.byte	0x1
	.byte	0x49
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x4
	.byte	0x4
	.long	0x95
	.uleb128 0xb
	.long	.LASF23
	.byte	0x1
	.byte	0x68
	.long	0x7f
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x1db
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x68
	.long	0x1db
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF17
	.byte	0x1
	.byte	0x68
	.long	0xa0
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xa
	.long	.LASF24
	.byte	0x1
	.byte	0x6a
	.long	0x175
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xa
	.long	.LASF25
	.byte	0x1
	.byte	0x6b
	.long	0x95
	.uleb128 0x2
	.byte	0x91
	.sleb128 -25
	.uleb128 0xa
	.long	.LASF26
	.byte	0x1
	.byte	0x6c
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x4
	.byte	0x4
	.long	0xa0
	.uleb128 0xc
	.long	.LASF30
	.byte	0x1
	.byte	0x83
	.long	0x7f
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x83
	.long	0x1db
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF17
	.byte	0x1
	.byte	0x83
	.long	0xa0
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xa
	.long	.LASF24
	.byte	0x1
	.byte	0x85
	.long	0x175
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xa
	.long	.LASF25
	.byte	0x1
	.byte	0x86
	.long	0x95
	.uleb128 0x2
	.byte	0x91
	.sleb128 -25
	.uleb128 0xa
	.long	.LASF26
	.byte	0x1
	.byte	0x87
	.long	0x4f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF11:
	.string	"int8_t"
.LASF23:
	.string	"big_to_little32"
.LASF5:
	.string	"short int"
.LASF9:
	.string	"sizetype"
.LASF13:
	.string	"uint8_t"
.LASF6:
	.string	"long long int"
.LASF8:
	.string	"long int"
.LASF22:
	.string	"negative"
.LASF19:
	.string	"my_atoi"
.LASF20:
	.string	"digits"
.LASF29:
	.string	"/home/nikhil/PESProject1"
.LASF18:
	.string	"my_itoa"
.LASF17:
	.string	"length"
.LASF1:
	.string	"unsigned char"
.LASF4:
	.string	"signed char"
.LASF7:
	.string	"long long unsigned int"
.LASF14:
	.string	"uint32_t"
.LASF0:
	.string	"unsigned int"
.LASF2:
	.string	"short unsigned int"
.LASF10:
	.string	"char"
.LASF12:
	.string	"int32_t"
.LASF28:
	.string	"conversion.c"
.LASF15:
	.string	"data"
.LASF24:
	.string	"tempVariable"
.LASF3:
	.string	"long unsigned int"
.LASF27:
	.string	"GNU C99 5.4.0 20160609 -mtune=generic -march=i686 -g -O0 -std=c99 -fstack-protector-strong"
.LASF30:
	.string	"little_to_big32"
.LASF21:
	.string	"number"
.LASF26:
	.string	"index"
.LASF16:
	.string	"base"
.LASF25:
	.string	"swapVariable"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
