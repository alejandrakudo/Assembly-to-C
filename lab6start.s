
lab6:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #28
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	str	r2, [fp, #-24]
	mov	r3, #0		@(
	str	r3, [fp, #-8]	@   i=0; )
	b	.L2
.L5:
	mov	r3, #0		@(
	str	r3, [fp, #-12]	@	j=0; )
	b	.L3
.L4:
	ldr	r3, [fp, #-8]	@(
	ldr	r2, [fp, #-24]
	mul	r2, r2, r3
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r3, r3, asl #2
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldr	r2, [fp, #-20]
	ldr	r1, [fp, #-24]
	mul	r2, r1, r2
	str	r2, [r3, #0]	@  a[i*cols +j] = rows * cols; )
	ldr	r3, [fp, #-12]	@(
	add	r3, r3, #1
	str	r3, [fp, #-12]	@   j++ )
.L3:
	ldr	r2, [fp, #-12]	@ (
	ldr	r3, [fp, #-24]
	cmp	r2, r3		@  i < cols; )
	blt	.L4
	ldr	r3, [fp, #-8]	@ (
	add	r3, r3, #1
	str	r3, [fp, #-8]	@  i++ )
.L2:
	ldr	r2, [fp, #-8]	@ (
	ldr	r3, [fp, #-20]
	cmp	r2, r3		@ i < rows; )
	blt	.L5
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr

