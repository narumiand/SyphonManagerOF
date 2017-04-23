#version 120

// this is how we receive the texture
uniform sampler2D tex0;

varying vec2 texCoordVarying;

void main()
{
    vec2 pos = texCoordVarying/2;
    
    gl_FragColor = texture2D(tex0, pos);
}