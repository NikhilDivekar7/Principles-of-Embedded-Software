	.file	"memory.c"
	.text
.Ltext0:
	.globl	my_memmove
	.type	my_memmove, @function
my_memmove:
.LFB0:
	.file 1 "memory.c"
	.loc 1 16 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	.loc 1 17 0
	movl	12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jbe	.L2
.LBB2:
	.loc 1 19 0
	movl	16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -8(%ebp)
	jmp	.L3
.L4:
	.loc 1 22 0 discriminator 3
	movl	-8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 19 0 discriminator 3
	subl	$1, -8(%ebp)
.L3:
	.loc 1 19 0 is_stmt 0 discriminator 1
	cmpl	$0, -8(%ebp)
	jns	.L4
	jmp	.L5
.L2:
.LBE2:
	.loc 1 25 0 is_stmt 1
	movl	12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jnb	.L5
.LBB3:
	.loc 1 27 0
	movl	$0, -4(%ebp)
	jmp	.L6
.L7:
	.loc 1 30 0 discriminator 3
	movl	-4(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 27 0 discriminator 3
	addl	$1, -4(%ebp)
.L6:
	.loc 1 27 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	.L7
.L5:
.LBE3:
	.loc 1 33 0 is_stmt 1
	movl	12(%ebp), %eax
	.loc 1 34 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	my_memmove, .-my_memmove
	.globl	my_memcpy
	.type	my_memcpy, @function
my_memcpy:
.LFB1:
	.loc 1 37 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
.LBB4:
	.loc 1 38 0
	movl	$0, -4(%ebp)
	jmp	.L10
.L11:
	.loc 1 40 0 discriminator 3
	movl	-4(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 38 0 discriminator 3
	addl	$1, -4(%ebp)
.L10:
	.loc 1 38 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	.L11
.LBE4:
	.loc 1 42 0 is_stmt 1
	movl	12(%ebp), %eax
	.loc 1 43 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_memcpy, .-my_memcpy
	.globl	my_memset
	.type	my_memset, @function
my_memset:
.LFB2:
	.loc 1 46 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	16(%ebp), %eax
	movb	%al, -20(%ebp)
.LBB5:
	.loc 1 48 0
	movl	$0, -8(%ebp)
	jmp	.L14
.L15:
	.loc 1 50 0 discriminator 3
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-20(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 48 0 discriminator 3
	addl	$1, -8(%ebp)
.L14:
	.loc 1 48 0 is_stmt 0 discriminator 1
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L15
.LBE5:
	.loc 1 52 0 is_stmt 1
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 53 0
	movl	-4(%ebp), %eax
	.loc 1 54 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	my_memset, .-my_memset
	.globl	my_memzero
	.type	my_memzero, @function
my_memzero:
.LFB3:
	.loc 1 57 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
.LBB6:
	.loc 1 58 0
	movl	$0, -4(%ebp)
	jmp	.L18
.L19:
.LBB7:
	.loc 1 60 0 discriminator 3
	movb	$0, -5(%ebp)
	.loc 1 61 0 discriminator 3
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-5(%ebp), %eax
	movb	%al, (%edx)
.LBE7:
	.loc 1 58 0 discriminator 3
	addl	$1, -4(%ebp)
.L18:
	.loc 1 58 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L19
.LBE6:
	.loc 1 63 0 is_stmt 1
	movl	8(%ebp), %eax
	.loc 1 64 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	my_memzero, .-my_memzero
	.globl	my_reverse
	.type	my_reverse, @function
my_reverse:
.LFB4:
	.loc 1 67 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	.loc 1 69 0
	movl	$0, -8(%ebp)
	.loc 1 70 0
	movl	$0, -4(%ebp)
	.loc 1 72 0
	movl	12(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L22
	.loc 1 74 0
	movl	12(%ebp), %eax
	shrl	%eax
	movl	%eax, -8(%ebp)
	jmp	.L23
.L22:
	.loc 1 78 0
	movl	12(%ebp), %eax
	subl	$1, %eax
	shrl	%eax
	movl	%eax, -8(%ebp)
.L23:
	.loc 1 81 0
	movl	$0, -4(%ebp)
	jmp	.L24
.L25:
	.loc 1 83 0 discriminator 3
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -9(%ebp)
	.loc 1 84 0 discriminator 3
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	12(%ebp), %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	leal	-1(%eax), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	.loc 1 85 0 discriminator 3
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-9(%ebp), %eax
	movb	%al, (%edx)
	.loc 1 81 0 discriminator 3
	addl	$1, -4(%ebp)
.L24:
	.loc 1 81 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jl	.L25
	.loc 1 87 0 is_stmt 1
	movl	8(%ebp), %eax
	.loc 1 88 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	my_reverse, .-my_reverse
	.globl	reserve_words
	.type	reserve_words, @function
reserve_words:
.LFB5:
	.loc 1 92 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	.loc 1 95 0
	subl	$12, %esp
	pushl	8(%ebp)
	call	malloc
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	.loc 1 96 0
	movl	$0, -16(%ebp)
	jmp	.L28
.L29:
	.loc 1 98 0 discriminator 3
	addl	$4, -12(%ebp)
	.loc 1 96 0 discriminator 3
	addl	$1, -16(%ebp)
.L28:
	.loc 1 96 0 is_stmt 0 discriminator 1
	movl	-16(%ebp), %eax
	cmpl	8(%ebp), %eax
	jb	.L29
	.loc 1 104 0 is_stmt 1
	movl	-12(%ebp), %eax
	.loc 1 105 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	reserve_words, .-reserve_words
	.globl	free_words
	.type	free_words, @function
free_words:
.LFB6:
	.loc 1 109 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	.loc 1 110 0
	movl	$0, 8(%ebp)
	.loc 1 111 0
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	free_words, .-free_words
.Letext0:
	.file 2 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h"
	.file 3 "/usr/include/stdint.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x30a
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF24
	.byte	0xc
	.long	.LASF25
	.long	.LASF26
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF11
	.byte	0x2
	.byte	0xd8
	.long	0x30
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF8
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF9
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF10
	.uleb128 0x2
	.long	.LASF12
	.byte	0x3
	.byte	0x24
	.long	0x4c
	.uleb128 0x2
	.long	.LASF13
	.byte	0x3
	.byte	0x26
	.long	0x5a
	.uleb128 0x2
	.long	.LASF14
	.byte	0x3
	.byte	0x30
	.long	0x37
	.uleb128 0x5
	.long	.LASF16
	.byte	0x1
	.byte	0xf
	.long	0x119
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x119
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0xf
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x6
	.string	"dst"
	.byte	0x1
	.byte	0xf
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0xf
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x8
	.long	.LBB2
	.long	.LBE2-.LBB2
	.long	0x102
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x13
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0xa
	.long	.LBB3
	.long	.LBE3-.LBB3
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x1b
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.long	0x9a
	.uleb128 0x5
	.long	.LASF17
	.byte	0x1
	.byte	0x24
	.long	0x119
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x179
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x24
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x6
	.string	"dst"
	.byte	0x1
	.byte	0x24
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x24
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xa
	.long	.LBB4
	.long	.LBE4-.LBB4
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x26
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.byte	0
	.uleb128 0x5
	.long	.LASF18
	.byte	0x1
	.byte	0x2d
	.long	0x1e1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x1e1
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x2d
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x2d
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.long	.LASF19
	.byte	0x1
	.byte	0x2d
	.long	0x9a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x9
	.string	"ptr"
	.byte	0x1
	.byte	0x2f
	.long	0x1e1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xa
	.long	.LBB5
	.long	.LBE5-.LBB5
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x30
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.long	0x84
	.uleb128 0x5
	.long	.LASF20
	.byte	0x1
	.byte	0x38
	.long	0x119
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x24b
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x38
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x38
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xa
	.long	.LBB6
	.long	.LBE6-.LBB6
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x3a
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xa
	.long	.LBB7
	.long	.LBE7-.LBB7
	.uleb128 0xc
	.long	.LASF19
	.byte	0x1
	.byte	0x3c
	.long	0x9a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -13
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x5
	.long	.LASF21
	.byte	0x1
	.byte	0x42
	.long	0x119
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x2a7
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x42
	.long	0x119
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x42
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF22
	.byte	0x1
	.byte	0x44
	.long	0x9a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -17
	.uleb128 0x9
	.string	"l"
	.byte	0x1
	.byte	0x45
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x46
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xd
	.long	.LASF23
	.byte	0x1
	.byte	0x5b
	.long	0x2e7
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x2e7
	.uleb128 0x7
	.long	.LASF15
	.byte	0x1
	.byte	0x5b
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x9
	.string	"i"
	.byte	0x1
	.byte	0x5d
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x9
	.string	"p"
	.byte	0x1
	.byte	0x5e
	.long	0x2e7
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.long	0x8f
	.uleb128 0xe
	.long	.LASF27
	.byte	0x1
	.byte	0x6c
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x6
	.string	"src"
	.byte	0x1
	.byte	0x6c
	.long	0x2e7
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
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
	.uleb128 0x3
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
	.uleb128 0x4
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
	.uleb128 0x5
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
	.uleb128 0x6
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
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
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
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
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
	.uleb128 0xd
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
	.uleb128 0xe
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
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
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
.LASF17:
	.string	"my_memcpy"
.LASF12:
	.string	"int8_t"
.LASF22:
	.string	"temp"
.LASF5:
	.string	"short int"
.LASF11:
	.string	"size_t"
.LASF9:
	.string	"sizetype"
.LASF21:
	.string	"my_reverse"
.LASF6:
	.string	"long long int"
.LASF18:
	.string	"my_memset"
.LASF19:
	.string	"value"
.LASF23:
	.string	"reserve_words"
.LASF14:
	.string	"uint8_t"
.LASF25:
	.string	"memory.c"
.LASF8:
	.string	"long int"
.LASF26:
	.string	"/home/nikhil/PESProject1"
.LASF15:
	.string	"length"
.LASF16:
	.string	"my_memmove"
.LASF1:
	.string	"unsigned char"
.LASF4:
	.string	"signed char"
.LASF7:
	.string	"long long unsigned int"
.LASF0:
	.string	"unsigned int"
.LASF2:
	.string	"short unsigned int"
.LASF27:
	.string	"free_words"
.LASF10:
	.string	"char"
.LASF13:
	.string	"int32_t"
.LASF3:
	.string	"long unsigned int"
.LASF24:
	.string	"GNU C99 5.4.0 20160609 -mtune=generic -march=i686 -g -O0 -std=c99 -fstack-protector-strong"
.LASF20:
	.string	"my_memzero"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
