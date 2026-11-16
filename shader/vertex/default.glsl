#version 460 core

layout (location = 0) in vec3 aPos;

uniform mat4 myMat;

out vec3 Pos;

void main(){
    gl_Position = myMat * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    Pos = aPos;
}