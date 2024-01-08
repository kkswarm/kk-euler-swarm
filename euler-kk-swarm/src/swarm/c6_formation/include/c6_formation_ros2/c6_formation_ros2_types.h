//
// File: c6_formation_ros2_types.h
//
// Code generated for Simulink model 'c6_formation_ros2'.
//
// Model version                  : 5.2
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Sat Oct 21 12:55:02 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_c6_formation_ros2_types_h_
#define RTW_HEADER_c6_formation_ros2_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_

// MsgType=builtin_interfaces/Time
struct SL_Bus_builtin_interfaces_Time
{
  int32_T sec;
  uint32_T nanosec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_std_msgs_Header
{
  // MsgType=builtin_interfaces/Time
  SL_Bus_builtin_interfaces_Time stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=frame_id_SL_Info:TruncateAction=warn 
  uint8_T frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=frame_id
  SL_Bus_ROSVariableLengthArrayInfo frame_id_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_geometry_msgs_Point
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_geometry_msgs_Quaternion
{
  real_T x;
  real_T y;
  real_T z;
  real_T w;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_geometry_msgs_Point position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_geometry_msgs_Quaternion orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
struct SL_Bus_geometry_msgs_PoseWithCovariance
{
  // MsgType=geometry_msgs/Pose
  SL_Bus_geometry_msgs_Pose pose;
  real_T covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_geometry_msgs_Vector3
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
struct SL_Bus_geometry_msgs_TwistWithCovariance
{
  // MsgType=geometry_msgs/Twist
  SL_Bus_geometry_msgs_Twist twist;
  real_T covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
struct SL_Bus_nav_msgs_Odometry
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=child_frame_id_SL_Info:TruncateAction=warn 
  uint8_T child_frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=child_frame_id
  SL_Bus_ROSVariableLengthArrayInfo child_frame_id_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_geometry_msgs_PoseWithCovariance pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_geometry_msgs_TwistWithCovariance twist;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_kkswarm_msgs_KKSwarmState_
#define DEFINED_TYPEDEF_FOR_SL_Bus_kkswarm_msgs_KKSwarmState_

// MsgType=kkswarm_msgs/KKSwarmState
struct SL_Bus_kkswarm_msgs_KKSwarmState
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;
  uint8_T socketfd;
  uint8_T mark;
  real_T linear_speed;
  real_T angular_speed;
  real_T left_encoder;
  real_T right_encoder;
  real_T acc_x;
  real_T acc_y;
  real_T gyro_z;
  real_T voltage;
};

#endif

// Custom Type definition for MATLABSystem: '<S393>/SinkBlock'
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include "rmw/types.h"
#include "rmw/types.h"
#ifndef struct_ros_slros2_internal_block_Sub_T
#define struct_ros_slros2_internal_block_Sub_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Sub_T

#ifndef struct_ros_slros2_internal_block_Pub_T
#define struct_ros_slros2_internal_block_Pub_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Pub_T

// Custom Type definition for MATLAB Function: '<S3>/uni_barrier_cert'
#ifndef struct_sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T
#define struct_sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T

struct sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T
{
  real_T xstar[13];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[64];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[13];
};

#endif                                // struct_sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T

#ifndef struct_sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T
#define struct_sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T

struct sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T
{
  real_T grad[13];
  real_T Hx[12];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T

#ifndef struct_snmmli8onVqbxLRLhWo5w6G_c6_fo_T
#define struct_snmmli8onVqbxLRLhWo5w6G_c6_fo_T

struct snmmli8onVqbxLRLhWo5w6G_c6_fo_T
{
  real_T FMat[169];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[624];
  real_T workspace2_[624];
};

#endif                                // struct_snmmli8onVqbxLRLhWo5w6G_c6_fo_T

#ifndef struct_s2v85VDFdoXWosLJGoY94IG_c6_fo_T
#define struct_s2v85VDFdoXWosLJGoY94IG_c6_fo_T

struct s2v85VDFdoXWosLJGoY94IG_c6_fo_T
{
  int32_T ldq;
  real_T QR[832];
  real_T Q[169];
  int32_T jpvt[64];
  int32_T mrows;
  int32_T ncols;
  real_T tau[13];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_s2v85VDFdoXWosLJGoY94IG_c6_fo_T

#ifndef struct_sivq9bjImOLkQfehLigQhXG_c6_fo_T
#define struct_sivq9bjImOLkQfehLigQhXG_c6_fo_T

struct sivq9bjImOLkQfehLigQhXG_c6_fo_T
{
  real_T workspace_double[832];
  int32_T workspace_int[64];
  int32_T workspace_sort[64];
};

#endif                                // struct_sivq9bjImOLkQfehLigQhXG_c6_fo_T

#ifndef struct_sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T
#define struct_sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T

struct sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[507];
  real_T bineq[39];
  real_T lb[13];
  real_T ub[13];
  int32_T indexLB[13];
  int32_T indexUB[13];
  int32_T indexFixed[13];
  int32_T mEqRemoved;
  real_T ATwset[832];
  real_T bwset[64];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[64];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[64];
  int32_T Wid[64];
  int32_T Wlocalidx[64];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T

#ifndef struct_scZhlMkNxPxOgM0FLkVrfPH_c6_fo_T
#define struct_scZhlMkNxPxOgM0FLkVrfPH_c6_fo_T

struct scZhlMkNxPxOgM0FLkVrfPH_c6_fo_T
{
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[3];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                                // struct_scZhlMkNxPxOgM0FLkVrfPH_c6_fo_T

// Parameters for system: '<S45>/MeasurementUpdate'
typedef struct P_MeasurementUpdate_c6_format_T_ P_MeasurementUpdate_c6_format_T;

// Parameters for system: '<S22>/ReducedQRN'
typedef struct P_ReducedQRN_c6_formation_ros_T_ P_ReducedQRN_c6_formation_ros_T;

// Parameters for system: '<S52>/Enabled Subsystem'
typedef struct P_EnabledSubsystem_c6_formati_T_ P_EnabledSubsystem_c6_formati_T;

// Parameters (default storage)
typedef struct P_c6_formation_ros2_T_ P_c6_formation_ros2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_c6_formation_ros2_T RT_MODEL_c6_formation_ros2_T;

#endif                                 // RTW_HEADER_c6_formation_ros2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
