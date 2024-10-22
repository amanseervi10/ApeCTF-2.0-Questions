#pushed to my docker hub (sudodeletebios) with "ozymandias:latest"
# sudo docker run -d -p 5184:5184 --rm -it sudodeletebios/ozymandias:latest

FROM ubuntu:22.04

RUN apt-get update 

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY ozymandias .
COPY flag.txt .
COPY ynetd .

#RUN chown -R root:root /home/ctf 
RUN chown -R root:ctf /home/ctf && chmod -R 750 /home/ctf

USER ctf
EXPOSE 5184
CMD ./ynetd -p 5184 ./ozymandias
