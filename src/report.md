# Отчет

## Part 1. Готовый докер

- Взять официальный докер образ с nginx и выкачать его при помощи docker pull
![docker](./img/1.1.png)


- Проверить наличие докер образа через docker images
![docker](.//img/1.2.png)


- Запустить докер образ через docker run -d [image_id|repository]
![docker](./img/1.3.png)

- Проверить, что образ запустился через docker ps
![docker](./img/1.4.png)

- Посмотреть информацию о контейнере через docker inspect [container_id|container_name]
![docker](./img/1.5.png)

- По выводу команды определить и поместить в отчёт:
    - размер контейнера 
    ![docker](./img/1.6.png)
    - список замапленных портов 
    ![docker](./img/1.7.png)
    - ip контейнера
    ![docker](./img/1.8.png)

- Остановить докер образ через docker stop [container_id|container_name]
![docker](./img/1.9.png)

- Проверить, что образ остановился через docker ps
![docker](./img/1.10.png)

- Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run
![docker](./img/1.11.png)


- Проверить, что в браузере по адресу localhost:80 доступна стартовая страница nginx
![docker](./img/1.12.png)


- Перезапустить докер контейнер через docker restart [container_id|container_name]
![docker](./img/1.13.png)

- Проверить любым способом, что контейнер запустился
![docker](./img/1.14.png)


## Part 2. Операции с контейнером

- Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec: 

    - Для этого нужно будет зайти в терминал внутри контейнера с помощью "docker exec /bin/sh". Посмотрим сначала название контейнера, чтобы использовать его в команде "exec", запускаем терминал внутри контейнера, переходим в папку /etc/nginx/ и читаем через "cat" файл "nginx.conf"

    ![docker](./img/2.1.png)


- Создать на локальной машине файл nginx.conf

- Настроить в нем по пути /status отдачу страницы статуса сервера nginx
![docker](./img/2.2.png)


- Скопировать созданный файл nginx.conf внутрь докер образа через команду docker cp
![docker](./img/2.3.png)


- Перезапустить nginx внутри докер образа через команду exec
![docker](./img/2.4.png)

- Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![docker](./img/2.5.png)

- Экспортировать контейнер в файл container.tar через команду export
![docker](./img/2.6.png)

- Остановить контейнер
![docker](./img/2.7.png)

- Удалить образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры
![docker](./img/2.8.png)

- Удалить остановленный контейнер
![docker](./img/2.9.png)


- Импортировать контейнер обратно через команду import
![docker](./img/2.10.png)

- Запустить импортированный контейнер
![docker](./img/2.11.png)

- Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![docker](./img/2.12.png)



## Part 3. Мини веб-сервер

- Написать мини сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!
![docker](./img/3.1.png)

- Запустить написанный мини сервер через spawn-fcgi на порту 8080
![docker](./img/3.2.png)

- Написать свой nginx.conf, который будет проксировать все запросы с 81 порта на 127.0.0.1:8080
![docker](./img/3.3.png)

- Проверить, что в браузере по localhost:81 отдается написанная вами страничка
![docker](./img/3.4.png)

- Положить файл nginx.conf по пути ./nginx/nginx.conf (это понадобится позже)



## Part 4. Свой докер

При написании докер образа избегайте множественных вызовов команд RUN

- Написать свой докер образ, который:

1) собирает исходники мини сервера на FastCgi из Части 3
2) запускает его на 8080 порту
3) копирует внутрь образа написанный ./nginx/nginx.conf
4) запускает nginx.

    - ![docker](./img/4.1.png)

    - ![docker](./img/4.2.png)

    - ![docker](./img/4.3.png)

    

- Собрать написанный докер образ через docker build при этом указав имя и тег
    - ![docker](./img/4.4.png)

- Проверить через docker images, что все собралось корректно
    - ![docker](./img/4.5.png)

- Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2)
    - ![docker](./img/4.6.png)

- Проверить, что по localhost:80 доступна страничка написанного мини сервера
    - ![docker](./img/4.7.png)

- Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx
    - ![docker](./img/4.8.png)

- Перезапустить докер образ
Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер образа должен обновиться самостоятельно без лишних действий
- Проверить, что теперь по localhost:80/status отдается страничка со статусом nginx
    - ![docker](./img/4.9.png)



## Part 5. Dockle

- После написания образа никогда не будет лишним проверить его на безопасность.
== Задание ==

- Просканировать образ из предыдущего задания через dockle [image_id|repository]
    - ![docker](./img/5.1.png)

- Исправить образ так, чтобы при проверке через dockle не было ошибок и предупреждений
    - ![docker](./img/5.2.png)
    - ![docker](./img/5.3.png)


## Part 6. Базовый Docker Compose

- Написать файл docker-compose.yml, с помощью которого:
    - ![docker](./img/6.1.png)

1) Поднять докер контейнер из Части 5 (он должен работать в локальной сети, т.е. не нужно использовать инструкцию EXPOSE и мапить порты на локальную машину)
    - ![docker](./img/6.2.png)


2) Поднять докер контейнер с nginx, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера
    - ![docker](./img/6.3.png)
- Замапить 8080 порт второго контейнера на 80 порт локальной машины

- Остановить все запущенные контейнеры

- Собрать и запустить проект с помощью команд docker-compose build:
    - ![docker](./img/6.4.png)

docker-compose up:
    - ![docker](./img/6.5.png)

- Проверить, что в браузере по localhost:80 отдается написанная вами страничка, как и ранее
    - ![docker](./img/6.6.png)