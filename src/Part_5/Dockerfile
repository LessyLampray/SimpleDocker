FROM nginx

USER root

WORKDIR /home/

RUN apt update && \
    apt install -y gcc libfcgi-dev spawn-fcgi && \
    useradd -ms /bin/bash dockeruser && \
    chown -R dockeruser:dockeruser /etc/nginx/nginx.conf; \
    chown -R dockeruser:dockeruser /var/cache/nginx; \
    chown -R dockeruser:dockeruser /home; \
    touch /var/run/nginx.pid; \
    chown -R dockeruser:dockeruser /var/run/nginx.pid; \
    rm -rf /var/lib/apt/lists

COPY ./server.c .
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .

USER dockeruser

HEALTHCHECK --interval=5m --timeout=3s CMD curl -f http://localhost/ || exit 1

ENTRYPOINT ["bash", "run.sh"]