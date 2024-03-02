FROM nginx

RUN apt update && \
    apt install -y gcc libfcgi-dev spawn-fcgi && \
    rm -rf /var/lib/apt/lists

COPY ./server.c .
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .

RUN chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx ./server.c

RUN chmod +x run.sh

ENTRYPOINT ["bash", "run.sh"]