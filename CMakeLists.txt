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


add_executable(GameEngine main.cpp GameEngine.cpp GameEngine.h Objects/GLMesh/GLMeshBase.cpp Objects/GLMesh/GLMeshBase.h Objects/Importer.cpp Objects/Importer.h Objects/GLMesh/GLMeshTexture.cpp Objects/GLMesh/GLMeshTexture.h Objects/GLMesh/GLMeshColour.cpp Objects/GLMesh/GLMeshColour.h Objects/GLMesh/ImportedMesh.cpp Objects/GLMesh/ImportedMesh.h Objects/Materials/Material.cpp Objects/Materials/Material.h WindowHandling/GLwindow.cpp WindowHandling/GLwindow.h WindowHandling/GLContext.cpp WindowHandling/GLContext.h Shading/ShaderLoader.cpp Shading/ShaderLoader.h Shading/ShaderProgramBase.cpp Shading/ShaderProgramBase.h Shading/TexturePhongShader.cpp Shading/TexturePhongShader.h Objects/TextureList.h Objects/GLMesh/hashFunction.h Scenes/Scene.cpp Scenes/Scene.h Scenes/GameScenes/TestScene.cpp Scenes/GameScenes/TestScene.h Objects/Object.cpp Objects/Object.h Scenes/SceneGeometries.cpp Scenes/SceneGeometries.h Scenes/ShaderProgramList.cpp Scenes/ShaderProgramList.h Shading/ShaderVariableList.cpp Shading/ShaderVariableList.h Scenes/RenderingList.cpp Scenes/RenderingList.h Objects/Geometry.cpp Objects/Geometry.h Scenes/GameScenes/GameObjects/PhongShadedObject.cpp Scenes/GameScenes/GameObjects/PhongShadedObject.h Objects/PhongShadedGeometry.cpp Objects/PhongShadedGeometry.h Objects/TexturedGeometry.cpp Objects/TexturedGeometry.h)
target_link_libraries(GameEngine
        PRIVATE SDL2
        PRIVATE SDL2_image
        PRIVATE GL
        -lGLU
        assimp
        )

