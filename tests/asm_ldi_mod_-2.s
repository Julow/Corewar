.name "test mod"
.comment ""

lol:
	ldi %:lol, %-2, r1
	sti r1, %:dest, %42
dest:
