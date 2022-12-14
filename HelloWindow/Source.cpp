#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main(int argc, char* argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Cruel OpenGL World", NULL, NULL);
	if (window == nullptr)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		std::cout << "Key 'Space' is pressed" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}


	/*
	* playing with changing color by pressing key
	*/
	static float step = 0.001;
	static bool flag = true;

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		std::cout << "Key '1' is pressed" << std::endl;
		glClearColor(1.0f - step, 1.0f - step, 1.0f - step, 1.0f);

		if (step < 1 && flag)
		{
			step += 0.001;
		}
		else if (flag) {
			flag = !flag;
		}

		if (step > 0 && !flag)
		{
			step -= 0.001;
		}
		else if (!flag)
		{
			flag = !flag;
		}
	}
}
