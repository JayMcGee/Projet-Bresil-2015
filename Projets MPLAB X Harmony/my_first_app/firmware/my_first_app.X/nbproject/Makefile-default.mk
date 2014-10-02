#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/wi_fire_pic32_mz/system_init.c ../src/system_config/wi_fire_pic32_mz/system_tasks.c ../src/main.c C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/120723158/system_init.o ${OBJECTDIR}/_ext/120723158/system_tasks.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1582439719/drv_tmr.o ${OBJECTDIR}/_ext/1226300807/sys_clk.o ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/1164753840/sys_queue.o ${OBJECTDIR}/_ext/161454199/sys_ports.o ${OBJECTDIR}/_ext/830912002/sys_tmr.o ${OBJECTDIR}/_ext/83237394/sys_devcon.o ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/120723158/system_init.o.d ${OBJECTDIR}/_ext/120723158/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d ${OBJECTDIR}/_ext/1226300807/sys_clk.o.d ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d ${OBJECTDIR}/_ext/1164753840/sys_queue.o.d ${OBJECTDIR}/_ext/161454199/sys_ports.o.d ${OBJECTDIR}/_ext/830912002/sys_tmr.o.d ${OBJECTDIR}/_ext/83237394/sys_devcon.o.d ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/120723158/system_init.o ${OBJECTDIR}/_ext/120723158/system_tasks.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1582439719/drv_tmr.o ${OBJECTDIR}/_ext/1226300807/sys_clk.o ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/1164753840/sys_queue.o ${OBJECTDIR}/_ext/161454199/sys_ports.o ${OBJECTDIR}/_ext/830912002/sys_tmr.o ${OBJECTDIR}/_ext/83237394/sys_devcon.o ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o

# Source Files
SOURCEFILES=../src/system_config/wi_fire_pic32_mz/system_init.c ../src/system_config/wi_fire_pic32_mz/system_tasks.c ../src/main.c C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048ECG100
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/120723158/system_init.o: ../src/system_config/wi_fire_pic32_mz/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/120723158 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/120723158/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/120723158/system_init.o.d" -o ${OBJECTDIR}/_ext/120723158/system_init.o ../src/system_config/wi_fire_pic32_mz/system_init.c   
	
${OBJECTDIR}/_ext/120723158/system_tasks.o: ../src/system_config/wi_fire_pic32_mz/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/120723158 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/120723158/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/120723158/system_tasks.o.d" -o ${OBJECTDIR}/_ext/120723158/system_tasks.o ../src/system_config/wi_fire_pic32_mz/system_tasks.c   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c   
	
${OBJECTDIR}/_ext/1582439719/drv_tmr.o: C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1582439719 
	@${RM} ${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1582439719/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/1582439719/drv_tmr.o C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c   
	
${OBJECTDIR}/_ext/1226300807/sys_clk.o: C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1226300807 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1226300807/sys_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1226300807/sys_clk.o.d" -o ${OBJECTDIR}/_ext/1226300807/sys_clk.o C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c   
	
${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o: C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1226300807 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c   
	
${OBJECTDIR}/_ext/1164753840/sys_queue.o: C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1164753840 
	@${RM} ${OBJECTDIR}/_ext/1164753840/sys_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1164753840/sys_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1164753840/sys_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1164753840/sys_queue.o.d" -o ${OBJECTDIR}/_ext/1164753840/sys_queue.o C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c   
	
${OBJECTDIR}/_ext/161454199/sys_ports.o: C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/161454199 
	@${RM} ${OBJECTDIR}/_ext/161454199/sys_ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/161454199/sys_ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/161454199/sys_ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/161454199/sys_ports.o.d" -o ${OBJECTDIR}/_ext/161454199/sys_ports.o C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c   
	
${OBJECTDIR}/_ext/830912002/sys_tmr.o: C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/830912002 
	@${RM} ${OBJECTDIR}/_ext/830912002/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/830912002/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/830912002/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/830912002/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/830912002/sys_tmr.o C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c   
	
${OBJECTDIR}/_ext/83237394/sys_devcon.o: C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/83237394 
	@${RM} ${OBJECTDIR}/_ext/83237394/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/83237394/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/83237394/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/83237394/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/83237394/sys_devcon.o C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c   
	
${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o: C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1973041708 
	@${RM} ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c   
	
else
${OBJECTDIR}/_ext/120723158/system_init.o: ../src/system_config/wi_fire_pic32_mz/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/120723158 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/120723158/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/120723158/system_init.o.d" -o ${OBJECTDIR}/_ext/120723158/system_init.o ../src/system_config/wi_fire_pic32_mz/system_init.c   
	
${OBJECTDIR}/_ext/120723158/system_tasks.o: ../src/system_config/wi_fire_pic32_mz/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/120723158 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/120723158/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/120723158/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/120723158/system_tasks.o.d" -o ${OBJECTDIR}/_ext/120723158/system_tasks.o ../src/system_config/wi_fire_pic32_mz/system_tasks.c   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c   
	
${OBJECTDIR}/_ext/1582439719/drv_tmr.o: C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1582439719 
	@${RM} ${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1582439719/drv_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1582439719/drv_tmr.o.d" -o ${OBJECTDIR}/_ext/1582439719/drv_tmr.o C:/microchip/harmony/v1_00/framework/driver/tmr/src/dynamic/drv_tmr.c   
	
${OBJECTDIR}/_ext/1226300807/sys_clk.o: C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1226300807 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1226300807/sys_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1226300807/sys_clk.o.d" -o ${OBJECTDIR}/_ext/1226300807/sys_clk.o C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk.c   
	
${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o: C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1226300807 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/1226300807/sys_clk_pic32mz.o C:/microchip/harmony/v1_00/framework/system/clk/src/sys_clk_pic32mz.c   
	
${OBJECTDIR}/_ext/1164753840/sys_queue.o: C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1164753840 
	@${RM} ${OBJECTDIR}/_ext/1164753840/sys_queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1164753840/sys_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1164753840/sys_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1164753840/sys_queue.o.d" -o ${OBJECTDIR}/_ext/1164753840/sys_queue.o C:/microchip/harmony/v1_00/framework/system/common/src/sys_queue.c   
	
${OBJECTDIR}/_ext/161454199/sys_ports.o: C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/161454199 
	@${RM} ${OBJECTDIR}/_ext/161454199/sys_ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/161454199/sys_ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/161454199/sys_ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/161454199/sys_ports.o.d" -o ${OBJECTDIR}/_ext/161454199/sys_ports.o C:/microchip/harmony/v1_00/framework/system/ports/src/sys_ports.c   
	
${OBJECTDIR}/_ext/830912002/sys_tmr.o: C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/830912002 
	@${RM} ${OBJECTDIR}/_ext/830912002/sys_tmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/830912002/sys_tmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/830912002/sys_tmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/830912002/sys_tmr.o.d" -o ${OBJECTDIR}/_ext/830912002/sys_tmr.o C:/microchip/harmony/v1_00/framework/system/tmr/src/sys_tmr.c   
	
${OBJECTDIR}/_ext/83237394/sys_devcon.o: C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/83237394 
	@${RM} ${OBJECTDIR}/_ext/83237394/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/83237394/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/83237394/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/83237394/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/83237394/sys_devcon.o C:/microchip/harmony/v1_00/framework/system/devcon/src/sys_devcon.c   
	
${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o: C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1973041708 
	@${RM} ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"../src/system_config/wi_fire_pic32_mz" -I"C:/microchip/harmony/v1_00/framework" -MMD -MF "${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1973041708/sys_int_pic32.o C:/microchip/harmony/v1_00/framework/system/int/src/sys_int_pic32.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/microchip/harmony/v1_00/bin/framework/peripheral/PIC32MZ2048ECG100_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    C:\microchip\harmony\v1_00\bin\framework\peripheral\PIC32MZ2048ECG100_peripherals.a       -mreserve=data@0x0:0x27F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/microchip/harmony/v1_00/bin/framework/peripheral/PIC32MZ2048ECG100_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    C:\microchip\harmony\v1_00\bin\framework\peripheral\PIC32MZ2048ECG100_peripherals.a      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/my_first_app.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
