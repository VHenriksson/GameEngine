cmake_minimum_required(VERSION 3.17)
project(GameEngine)


find_package(SDL2 REQUIRED SDL2)
find_package(SDL2 REQUIRED SDL2_image)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)


include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)

include_directories()


add_executable(GameEngine main.cpp GameEngine.cpp GameEngine.h Objects/GLMesh/GLMeshBase.cpp Objects/GLMesh/GLMeshBase.h Objects/PhongShadedObject.cpp Objects/PhongShadedObject.h Objects/Importer.cpp Objects/Importer.h Objects/GLMesh/GLMeshTexture.cpp Objects/GLMesh/GLMeshTexture.h Objects/GLMesh/GLMeshColour.cpp Objects/GLMesh/GLMeshColour.h Objects/GLMesh/ImportedMesh.cpp Objects/GLMesh/ImportedMesh.h Objects/Materials/Material.cpp Objects/Materials/Material.h WindowHandling/GLwindow.cpp WindowHandling/GLwindow.h WindowHandling/GLContext.cpp WindowHandling/GLContext.h Shading/ShaderLoader.cpp Shading/ShaderLoader.h Shading/ShaderProgram.cpp Shading/ShaderProgram.h)
target_link_libraries(GameEngine
        PRIVATE SDL2
        PRIVATE SDL2_image
        PRIVATE GL
        -lGLU
        assimp
        )

