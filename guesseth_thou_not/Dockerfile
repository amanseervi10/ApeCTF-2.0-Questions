#pushed to my docker hub (sudodeletebios) with "guesseth_thou_not:latest"

# sudo docker run -d -p 32014:32014 --rm -it sudodeletebios/guesseth_thou_not

FROM ubuntu:22.04

RUN apt-get update

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY guess_the_number .
COPY ynetd .

#RUN chown -R root:root /home/ctf
RUN chown -R root:ctf /home/ctf && chmod -R 750 /home/ctf

USER ctf
EXPOSE 32014
CMD ./ynetd -p 32014 ./guess_the_number
