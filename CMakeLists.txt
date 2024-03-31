cmake_minimum_required(VERSION 3.10)

# Define o nome do seu projeto
project(casa-vegetativa)

# Adiciona a pasta de bibliotecas ao caminho de link
link_directories(casa-vegetativa/libraries)

# Adiciona todos os arquivos .cpp na pasta src ao seu projeto
file(GLOB SOURCES "src/*.cpp")

# Adiciona o diretório de inclusão
include_directories(casa-vegetativa/include)

# Cria um executável com os arquivos fonte
add_executable(MyExe ${SOURCES})

# Link as bibliotecas ao seu projeto
target_link_libraries(MyExe libraries)