CC = gcc
CFLAGS = -Wall -fno-stack-protector -z execstack -O0

all: auth

auth: auth.c
	$(CC) $(CFLAGS) $< -o $@

test: auth
	# Test valid password
	echo "s3cr3t" | ./auth | grep "Access granted"
	# Test invalid password
	echo "wrong" | ./auth | grep "Access denied"

clean:
	rm -f auth
