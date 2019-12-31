#pragma once
#include <stack>
#include "Scene.hpp"


namespace TstBits {
    typedef std::unique_ptr<Scene> ScenePtr;

    class SceneManager 
    {
    public:
        SceneManager() = default;
        ~SceneManager();

        static void LoadScene(ScenePtr, bool = true);
        static void DestroyAll();
        static Scene& GetCurrentScene();
    private:
        static std::stack<ScenePtr> scenes;
    };
}