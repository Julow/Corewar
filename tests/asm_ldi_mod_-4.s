.name "test mod"
.comment ""

lol:
	ldi %:lol, %-4, r1
	sti r1, %:dest, %42
dest:
