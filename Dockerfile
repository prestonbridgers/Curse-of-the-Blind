FROM debian

RUN mkdir /home/cotb && apt-get update && apt-get install -y \
	libncurses-dev \
	make \
	gcc

COPY . /home/cotb/

