FROM nginx

COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .

RUN chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chown -R nginx:nginx run.sh

RUN chmod +x run.sh

USER nginx
ENTRYPOINT ["bash", "run.sh"]