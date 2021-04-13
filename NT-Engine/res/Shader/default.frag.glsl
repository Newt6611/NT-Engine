#version 450 core


in VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	mat3 TBN;
} fs_in;

struct Material {
	sampler2D texture_diffuse1;
	sampler2D texture_specular1;
	sampler2D texture_normal1;
	//vec3 albedo;
	//vec3 diffuse;
	//vec3 specular;
	float shininess;
};


uniform Material material;

uniform vec3 viewPos;

uniform vec3 lightColor;
uniform vec3 lightDir;

out vec4 FragColor;

void main()
{
	// Directional Light Test
	vec3 normal = texture(material.texture_normal1, fs_in.TexCoords).rgb;
	normal = normalize(normal * 2.0f - 1.0f);
	normal = fs_in.TBN * normal;

	vec3 viewDir = normalize(viewPos - fs_in.FragPos);
	vec3 lightRefl = normalize(reflect(-lightDir, normal));
	
	vec3 ambient = texture(material.texture_diffuse1, fs_in.TexCoords).rgb * lightColor;

	float diff = max(dot(normal, normalize(lightDir)), 0);
	vec3 diffuse = diff * texture(material.texture_diffuse1, fs_in.TexCoords).rgb;


	vec3 halfWay = normalize(lightDir + viewDir);
	float spec = pow(max(dot(normal, halfWay), 0), material.shininess);
	vec3 specular = vec3(1) * spec;

	vec4 result = vec4(ambient + diffuse + specular, 1);

	FragColor = vec4(normal,1);
}