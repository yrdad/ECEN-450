obj-m := audio_test.o
audio_test-objs := xac97.o audio_buffer.o

all:
	make -C ~/ecen449/lab5/linux-2.6.35.7 M=$(PWD) modules

clean:
	make -C ~/ecen449/lab5/linux-2.6.35.7 M=$(PWD) clean
