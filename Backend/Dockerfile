FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Essential packages install karein
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    git \
    curl \
    libasio-dev \
    && rm -rf /var/lib/apt/lists/*

# Crow framework ko crow folder ke sath setup karein
RUN mkdir -p /usr/include/crow \
    && curl -sSL https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h -o /usr/include/crow_all.h \
    && echo '#include "../crow_all.h"' > /usr/include/crow/json.h \
    && echo '#include "../crow_all.h"' > /usr/include/crow.h

WORKDIR /app

COPY . .

# Application compile karein
RUN g++ -std=c++17 -O3 main.cpp TaskManager.cpp PriorityManager.cpp FileManager.cpp -o scheduler -lpthread

EXPOSE 18080

CMD ["./scheduler"]
