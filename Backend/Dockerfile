FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    git \
    libasio-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN g++ -std=c++17 -O3 main.cpp TaskManager.cpp PriorityManager.cpp FileManager.cpp -o scheduler -lpthread

EXPOSE 18080

CMD ["./scheduler"]