.name "zork"
	.comment "just a basic living prog"

	xor %:l2, %:l2, r1
l2:
	and r1,%0,r1
	sti r1,%:live,%1
	zjmp %:live
live:	live %:live
	and r1,%0,r1
	zjmp %:live

