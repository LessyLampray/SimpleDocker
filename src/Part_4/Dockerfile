FROM nginx

RUN apt update && \
    apt install -y gcc libfcgi-dev spawn-fcgi

COPY ./server.c .
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .

ENTRYPOINT ["bash", "run.sh"]