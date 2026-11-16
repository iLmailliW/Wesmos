#version 460 core

in vec3 Pos;
out vec4 FragColor;

void main()
{
    FragColor = vec4(Pos.x, Pos.y, 1.0, 1.0);
}