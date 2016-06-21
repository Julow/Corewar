.name "test mod"
.comment ""

lol:
	ld %-559038737, r1
	sti r1, %:lol, %0
	ldi %:lol, %0, r2
	sti r2, %:dest, %42
dest:
