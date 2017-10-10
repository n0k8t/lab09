[![Build Status](https://travis-ci.org/n0k8t/lab05.svg?branch=master)](https://travis-ci.org/n0k8t/lab05)
## Laboratory work V

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **Travis CI**

```ShellSession
$ open https://travis-ci.org
```

## Tasks

- [x] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [x] 2. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [x] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [x] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [x] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [x] 8. Выполнить инструкцию учебного материала
- [x] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Переменные окружения
```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_TOKEN=<полученный_токен>
```
Копирование репозитория лабораторной работы №4
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 lab05
$ cd lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```
Запись в файл для Travis CI
```ShellSession
$ cat > .travis.yml <<EOF
language: cpp
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```
Авторизация с помощью токена
```ShellSession
$ travis login --github-token ${GITHUB_TOKEN}
```
Проверка .travis.yml
```ShellSession
$ travis lint
```
Вставка в текст
```ShellSession
$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md
```
Коммиты
```ShellSession
$ git add .travis.yml
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
```
Команды travis
```ShellSession
$ travis lint     
Warnings for .travis.yml:
[x] value for addons section is empty, dropping
[x] in addons section: unexpected key apt, dropping
$ travis accounts     #показывает аккаунты и их статусы
n0k8t (Timofey Tyrin): subscribed, 33 repositories
$ travis sync         #синхронизация
synchronizing: ... done
$ travis repos	      #показывает репозитории и их активность
n0k8t/3rd-SEM-lab1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/3rd-SEM-lab2 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/3rd-semester (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/HW_1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab2_Var10 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab3_Var12 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab3_Var9 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab4_Var11 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab5_Var11 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab6_Zoo (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab7_Part1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab7_Part2 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Lab7d (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Add1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab10 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab3 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab4 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab5 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab6 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab7 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab8 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_Lab9 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/Modul2_lab2 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/boolean_function (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/functional (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/lab03 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/lab04 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/lab05 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/lab1_TString (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/qsort (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/thread (active: no, admin: yes, push: yes, pull: yes)
Description: ???

n0k8t/tmp (active: no, admin: yes, push: yes, pull: yes)
Description: ???
$ travis enable       #активация проекта
Detected repository as n0k8t/lab05, is this correct? |yes| 
n0k8t/lab05: enabled :)
$ travis whatsup      #показывает последний действия с файлами
nothing to show
$ travis branches     #показывает ветки
$ travis history      #история
$ travis show         #показывает общую информацию о недавних сборках
no build yet for n0k8t/lab05
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Travis Client](https://github.com/travis-ci/travis.rb)
- [AppVeyour](https://www.appveyor.com/)
- [GitLab CI](https://about.gitlab.com/gitlab-ci/)

```
Copyright (c) 2017 Братья Вершинины
```
