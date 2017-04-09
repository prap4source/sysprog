all:  test
test: align.c    
	$(CC)  -o align align.c
clean:
	rm -rf align
