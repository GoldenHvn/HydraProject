#ifndef HYDRA_BASICMESHSHADER_H
#define HYDRA_BASICMESHSHADER_H

namespace hydra {

// Vertex shader for DirectX 12 meshes (HLSL)
static const char g_basicMeshShader[] = R"(
cbuffer Matrices : register(b0)
{
    float4x4 World;
    float4x4 ViewProj;
    float4   MiscParams; // x = specular power
};

struct VSInput {
    float3 position : POSITION;
    float3 normal   : NORMAL;
    float2 texcoord : TEXCOORD0;
};

struct VSOutput {
    float4 pos      : SV_POSITION;
    float2 tex0     : TEXCOORD0;
    float2 tex1     : TEXCOORD1;
    float  fog      : FOG;
};

VSOutput main(VSInput input)
{
    VSOutput output;
    float4 worldPos = mul(float4(input.position, 1.0f), World);
    output.pos = mul(worldPos, ViewProj);

    float3 viewDir = -worldPos.xyz;
    float invZ = 1.0f / output.pos.w;
    float2 proj = output.pos.xy * invZ + MiscParams.yy;

    float3 n = normalize(mul(input.normal, (float3x3)World));
    float2 t0 = proj + n.xy * MiscParams.xx;
    output.tex0 = t0;

    output.fog = invZ;

    float3 lightDir = normalize(MiscParams.xyz - worldPos.xyz);
    float NdotL = dot(n, lightDir);
    float3 r = reflect(-lightDir, n);
    float spec = pow(saturate(dot(r, viewDir)), MiscParams.w);
    output.tex1 = float2(NdotL * 0.5f + 0.5f, spec);
    return output;
}
)";

} // namespace hydra

#endif // HYDRA_BASICMESHSHADER_H
