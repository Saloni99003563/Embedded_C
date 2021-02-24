	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"test.c"
	.text
	.global	numbers
	.data
	.align	2
	.type	numbers, %object
	.size	numbers, 68
numbers:
	.word	456
	.word	345
	.word	678
	.word	567
	.word	890
	.word	456
	.word	3456
	.word	123
	.word	765
	.word	456
	.word	896
	.word	456
	.word	678
	.word	987
	.word	0
	.word	145
	.word	90
	.global	someData
	.align	2
	.type	someData, %object
	.size	someData, 4
someData:
	.word	90
	.text
	.align	1
	.global	array_fill_numbers
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	array_fill_numbers, %function
array_fill_numbers:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #16
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	movs	r3, #0
	str	r3, [r7, #12]
	b	.L2
.L3:
	bl	rand
	mov	r2, r0
	ldr	r3, [r7, #12]
	lsls	r3, r3, #2
	ldr	r1, [r7, #4]
	add	r1, r1, r3
	ldr	r3, .L4
	smull	r0, r3, r3, r2
	asrs	r0, r3, #6
	asrs	r3, r2, #31
	subs	r3, r0, r3
	mov	r0, #1000
	mul	r3, r0, r3
	subs	r3, r2, r3
	str	r3, [r1]
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L2:
	ldr	r2, [r7, #12]
	ldr	r3, [r7]
	cmp	r2, r3
	bcc	.L3
	nop
	nop
	adds	r7, r7, #16
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L5:
	.align	2
.L4:
	.word	274877907
	.size	array_fill_numbers, .-array_fill_numbers
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%s\000"
	.align	2
.LC1:
	.ascii	"%5d  \000"
	.text
	.align	1
	.global	display_numbers
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	display_numbers, %function
display_numbers:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #24
	add	r7, sp, #0
	str	r0, [r7, #12]
	str	r1, [r7, #8]
	str	r2, [r7, #4]
	ldr	r1, [r7, #4]
	ldr	r0, .L9
	bl	printf
	movs	r3, #0
	str	r3, [r7, #20]
	b	.L7
.L8:
	ldr	r3, [r7, #20]
	lsls	r3, r3, #2
	ldr	r2, [r7, #12]
	add	r3, r3, r2
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L9+4
	bl	printf
	ldr	r3, [r7, #20]
	adds	r3, r3, #1
	str	r3, [r7, #20]
.L7:
	ldr	r2, [r7, #20]
	ldr	r3, [r7, #8]
	cmp	r2, r3
	bcc	.L8
	movs	r0, #10
	bl	putchar
	nop
	adds	r7, r7, #24
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L10:
	.align	2
.L9:
	.word	.LC0
	.word	.LC1
	.size	display_numbers, .-display_numbers
	.align	1
	.global	swap_numbers
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	swap_numbers, %function
swap_numbers:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #20
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	ldr	r3, [r7, #4]
	ldr	r3, [r3]
	str	r3, [r7, #12]
	ldr	r3, [r7]
	ldr	r2, [r3]
	ldr	r3, [r7, #4]
	str	r2, [r3]
	ldr	r3, [r7]
	ldr	r2, [r7, #12]
	str	r2, [r3]
	ldr	r3, .L12
	movs	r2, #10
	str	r2, [r3]
	nop
	adds	r7, r7, #20
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L13:
	.align	2
.L12:
	.word	someData
	.size	swap_numbers, .-swap_numbers
	.align	1
	.global	bubble_sort
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	bubble_sort, %function
bubble_sort:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #24
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	movs	r3, #0
	str	r3, [r7, #12]
	movs	r3, #0
	str	r3, [r7, #20]
	b	.L15
.L21:
	movs	r3, #0
	str	r3, [r7, #12]
	movs	r3, #0
	str	r3, [r7, #16]
	b	.L16
.L18:
	ldr	r3, [r7, #16]
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r3, r3, r2
	ldr	r2, [r3]
	ldr	r3, [r7, #16]
	adds	r3, r3, #1
	lsls	r3, r3, #2
	ldr	r1, [r7, #4]
	add	r3, r3, r1
	ldr	r3, [r3]
	cmp	r2, r3
	ble	.L17
	ldr	r3, [r7, #16]
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	adds	r0, r2, r3
	ldr	r3, [r7, #16]
	adds	r3, r3, #1
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r3, r3, r2
	mov	r1, r3
	bl	swap_numbers
	movs	r3, #1
	str	r3, [r7, #12]
.L17:
	ldr	r3, [r7, #16]
	adds	r3, r3, #1
	str	r3, [r7, #16]
.L16:
	ldr	r3, [r7, #20]
	ldr	r2, [r7]
	subs	r3, r2, r3
	subs	r2, r3, #1
	ldr	r3, [r7, #16]
	cmp	r2, r3
	bhi	.L18
	ldr	r3, [r7, #12]
	cmp	r3, #0
	beq	.L22
	ldr	r3, [r7, #20]
	adds	r3, r3, #1
	str	r3, [r7, #20]
.L15:
	ldr	r3, [r7]
	subs	r2, r3, #1
	ldr	r3, [r7, #20]
	cmp	r2, r3
	bhi	.L21
	b	.L23
.L22:
	nop
.L23:
	nop
	adds	r7, r7, #24
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
	.size	bubble_sort, .-bubble_sort
	.align	1
	.global	insertion_sort
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	insertion_sort, %function
insertion_sort:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #28
	add	r7, sp, #0
	str	r0, [r7, #4]
	str	r1, [r7]
	movs	r3, #1
	str	r3, [r7, #20]
	b	.L25
.L29:
	ldr	r3, [r7, #20]
	subs	r3, r3, #1
	str	r3, [r7, #16]
	ldr	r3, [r7, #20]
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r3, r3, r2
	ldr	r3, [r3]
	str	r3, [r7, #12]
	b	.L26
.L28:
	ldr	r3, [r7, #16]
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r2, r2, r3
	ldr	r3, [r7, #16]
	adds	r3, r3, #1
	lsls	r3, r3, #2
	ldr	r1, [r7, #4]
	add	r3, r3, r1
	ldr	r2, [r2]
	str	r2, [r3]
	ldr	r3, [r7, #16]
	subs	r3, r3, #1
	str	r3, [r7, #16]
.L26:
	ldr	r3, [r7, #16]
	cmp	r3, #0
	blt	.L27
	ldr	r3, [r7, #16]
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r3, r3, r2
	ldr	r3, [r3]
	ldr	r2, [r7, #12]
	cmp	r2, r3
	blt	.L28
.L27:
	ldr	r3, [r7, #16]
	adds	r3, r3, #1
	lsls	r3, r3, #2
	ldr	r2, [r7, #4]
	add	r3, r3, r2
	ldr	r2, [r7, #12]
	str	r2, [r3]
	ldr	r3, [r7, #20]
	adds	r3, r3, #1
	str	r3, [r7, #20]
.L25:
	ldr	r3, [r7, #20]
	ldr	r2, [r7]
	cmp	r2, r3
	bhi	.L29
	nop
	nop
	adds	r7, r7, #28
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
	.size	insertion_sort, .-insertion_sort
	.section	.rodata
	.align	2
.LC2:
	.ascii	"B-unsorted array :\000"
	.align	2
.LC3:
	.ascii	"B-sorted array   :\000"
	.align	2
.LC4:
	.ascii	"I-unsorted array :\000"
	.align	2
.LC5:
	.ascii	"I-sorted array   :\000"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r3, #17
	str	r3, [r7, #4]
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	array_fill_numbers
	ldr	r2, .L32+4
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	display_numbers
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	bubble_sort
	ldr	r2, .L32+8
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	display_numbers
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	array_fill_numbers
	ldr	r2, .L32+12
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	display_numbers
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	insertion_sort
	ldr	r2, .L32+16
	ldr	r1, [r7, #4]
	ldr	r0, .L32
	bl	display_numbers
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L33:
	.align	2
.L32:
	.word	numbers
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10-2020-q4-major) 10.2.1 20201103 (release)"
