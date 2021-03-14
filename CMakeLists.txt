cmake_minimum_required(VERSION 3.10)
project(GameEngine)


find_package(SDL2 REQUIRED SDL2)
find_package(SDL2 REQUIRED SDL2_image)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)


include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)

include_directories()


add_executable(GameEngine main.cpp GameEngine.cpp GameEngine.h Objects/GLMesh/GLMeshBase.cpp Objects/GLMesh/GLMeshBase.h Objects/Importer.cpp Objects/Importer.h Objects/GLMesh/GLMeshTexture.cpp Objects/GLMesh/GLMeshTexture.h Objects/GLMesh/GLMeshColour.cpp Objects/GLMesh/GLMeshColour.h Objects/GLMesh/ImportedMesh.cpp Objects/GLMesh/ImportedMesh.h Objects/Materials/Material.cpp Objects/Materials/Material.h WindowHandling/GLwindow.cpp WindowHandling/GLwindow.h WindowHandling/GLContext.cpp WindowHandling/GLContext.h Shading/ShaderLoader.cpp Shading/ShaderLoader.h Shading/ShaderProgramBase.cpp Shading/ShaderProgramBase.h Shading/TexturePhongShader.cpp Shading/TexturePhongShader.h Objects/MaterialList.h Objects/GLMesh/hashFunction.h Scenes/Scene.cpp Scenes/Scene.h Scenes/GameScenes/CaterpillarScene.cpp Scenes/GameScenes/CaterpillarScene.h Objects/Object.cpp Objects/Object.h Scenes/GeometryList.cpp Scenes/GeometryList.h Scenes/RenderingList.cpp Scenes/RenderingList.h Objects/Geometry.cpp Objects/Geometry.h Scenes/GameScenes/GameObjects/PhongShadedObject.cpp Scenes/GameScenes/GameObjects/PhongShadedObject.h Objects/PhongShadedGeometry.cpp Objects/PhongShadedGeometry.h Objects/TexturedGeometry.cpp Objects/TexturedGeometry.h Shading/PhongShader.cpp Shading/PhongShader.h InputManager/InputManagerBase.cpp InputManager/InputManagerBase.h InputManager/InputManagerCaterpillar.cpp InputManager/InputManagerCaterpillar.h Scenes/GameScenes/GameObjects/Planet.cpp Scenes/GameScenes/GameObjects/Planet.h Scenes/GameScenes/GameObjects/Plupp.cpp Scenes/GameScenes/GameObjects/Plupp.h Scenes/GameScenes/GameObjects/Food.cpp Scenes/GameScenes/GameObjects/Food.h Scenes/GameScenes/GameObjects/Caterpillar.cpp Scenes/GameScenes/GameObjects/Caterpillar.h Scenes/GameScenes/GameObjects/Caterpillar.cpp Scenes/GameScenes/GameObjects/Caterpillar.h GamePart.h GamePartBase.cpp GamePartBase.h)
target_link_libraries(GameEngine
        PRIVATE SDL2
        PRIVATE SDL2_image
        PRIVATE GL
        -lGLU
        assimp
        )

