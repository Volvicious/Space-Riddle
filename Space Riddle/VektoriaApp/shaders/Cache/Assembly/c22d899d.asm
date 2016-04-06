//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// transparentDepthTex               texture   float       2dMS4   22        1
// opaqueDepthTex                    texture   float       2dMS4   23        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xy  
// TEXCOORD                 0   xy          1     NONE  float       
// TEXCOORD                 1   xyzw        2     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_TARGET                0   xyzw        0   TARGET  float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_resource_texture2dms(4) (float,float,float,float) t22
dcl_resource_texture2dms(4) (float,float,float,float) t23
dcl_input_ps_siv linear noperspective v0.xy, position
dcl_output o0.xyzw
dcl_temps 2

#line 71 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\source\godrays.hlsl"
ftoi r0.xy, v0.xyxx
mov r0.zw, l(0,0,0,0)
ldms_indexable(texture2dms)(float,float,float,float) r0.x, r0.xyzw, t23.xyzw, l(0)
mov r0.x, r0.x  // f4Color<0:Inf>
ftoi r1.xy, v0.xyxx
mov r1.zw, l(0,0,0,0)
ldms_indexable(texture2dms)(float,float,float,float) r0.y, r1.xyzw, t22.yxzw, l(0)
mov r0.y, r0.y  // f4Color<1:Inf>

#line 75
lt r0.z, r0.y, r0.x
movc r0.x, r0.z, r0.x, r0.y  // f4Color<0:Inf>
mul r0.x, r0.x, l(1000.000000)
mov r0.x, -r0.x
add r1.x, r0.x, l(1.000000)  // f4Color<0:Inf>
add r1.y, r0.x, l(1.000000)  // f4Color<1:Inf>
add r1.z, r0.x, l(1.000000)  // f4Color<2:Inf>
mov r1.w, l(1.000000)  // f4Color<3: 1f>
max r0.xyzw, r1.xyzw, l(0.000000, 0.000000, 0.000000, 0.000000)
min r0.xyzw, r0.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)  // f4Color<0:[0f,1f],1:[0f,1f],2:[0f,1f],3: 1f>
mov o0.xyzw, r0.xyzw  // PS_GODRAYS_PRE<0:[0f,1f],1:[0f,1f],2:[0f,1f],3: 1f>
ret 
// Approximately 20 instruction slots used
