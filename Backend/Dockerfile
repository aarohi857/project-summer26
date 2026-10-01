FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies including curl and build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    git \
    curl \
    libasio-dev \
    && rm -rf /var/lib/apt/lists/*

# Download Crow header file
RUN curl -sSL https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h -o /usr/include/crow_all.h

WORKDIR /app

COPY . .

# Build application
RUN g++ -std=c++17 -O3 main.cpp TaskManager.cpp PriorityManager.cpp FileManager.cpp -o scheduler -lpthread

EXPOSE 18080

CMD ["./scheduler"]
