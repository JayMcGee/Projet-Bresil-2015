# start of do file

################################################################################
# LAYERSET DEFINITIONS                                                         #
################################################################################

################################################################################
# CLEARANCE RULES                                                              #
################################################################################
# rule assignments for PCB clearances                                          #
################################################################################
rule PCB (width 12)
rule PCB (clearance 5 (type buried_via_gap))
rule PCB (clearance 12 (type wire_wire))
rule PCB (clearance 12 (type wire_smd))
rule PCB (clearance 12 (type wire_pin))
rule PCB (clearance 5 (type wire_via))
rule PCB (clearance 12 (type smd_smd))
rule PCB (clearance 12 (type smd_pin))
rule PCB (clearance 5 (type smd_via))
rule PCB (clearance 12 (type pin_pin))
rule PCB (clearance 5 (type pin_via))
rule PCB (clearance 5 (type via_via))
rule PCB (clearance 5 (type test_test))
rule PCB (clearance 5 (type test_wire))
rule PCB (clearance 5 (type test_smd))
rule PCB (clearance 5 (type test_pin))
rule PCB (clearance 5 (type test_via))
rule PCB (clearance 0 (type area_wire))
rule PCB (clearance 0 (type area_smd))
rule PCB (clearance 0 (type area_area))
rule PCB (clearance 0 (type area_pin))
rule PCB (clearance 0 (type area_via))
rule PCB (clearance 0 (type area_test))

rule PCB (clearance 5 (type microvia_microvia))
set microvia_microvia on
rule PCB (clearance 5 (type microvia_thrupin))
set microvia_thrupin on
rule PCB (clearance 5 (type microvia_smdpin))
set microvia_smdpin on
rule PCB (clearance 5 (type microvia_thruvia))
set microvia_thruvia on
rule PCB (clearance 5 (type microvia_bbvia))
set microvia_bbvia on
rule PCB (clearance 5 (type microvia_wire))
set microvia_wire on
rule PCB (clearance 5 (type bbvia_bbvia))
set bbvia_bbvia on
rule PCB (clearance 5 (type microvia_testpin))
set microvia_testpin on
rule PCB (clearance 5 (type bbvia_thrupin))
set bbvia_thrupin on
rule PCB (clearance 5 (type microvia_testvia))
set microvia_testvia on
rule PCB (clearance 5 (type bbvia_smdpin))
set bbvia_smdpin on
rule PCB (clearance 5 (type microvia_bondpad))
set microvia_bondpad on
rule PCB (clearance 5 (type bbvia_thruvia))
set bbvia_thruvia on
rule PCB (clearance 5 (type microvia_area))
set microvia_area on
rule PCB (clearance 5 (type bbvia_wire))
set bbvia_wire on
rule PCB (clearance 8 (type nhole_pin))
set nhole_pin off
rule PCB (clearance 8 (type nhole_via))
set nhole_via off
rule PCB (clearance 5 (type bbvia_area))
set bbvia_area on
rule PCB (clearance 8 (type nhole_wire))
set nhole_wire off
rule PCB (clearance 8 (type nhole_area))
set nhole_area off
rule PCB (clearance 8 (type nhole_nhole))
set nhole_nhole off
rule PCB (clearance 0 (type mhole_pin))
set mhole_pin off
rule PCB (clearance 5 (type bbvia_testpin))
set bbvia_testpin on
rule PCB (clearance 0 (type mhole_via))
set mhole_via off
rule PCB (clearance 5 (type bbvia_testvia))
set bbvia_testvia on
rule PCB (clearance 0 (type mhole_wire))
set mhole_wire off
rule PCB (clearance 0 (type mhole_area))
set mhole_area off
rule PCB (clearance 0 (type mhole_nhole))
set mhole_nhole off
rule PCB (clearance 0 (type mhole_mhole))
set mhole_mhole off
rule PCB (clearance 5 (type bbvia_bondpad))
set bbvia_bondpad on

################################################################################
# rule assignments for net clearances                                          #
################################################################################
rule net N94966 (width 20)
rule net N61373 (width 20)
rule net N78169 (width 20)
rule net N78069 (width 20)
rule net GND (width 25)
rule net XBEESLEEP (width 20)
rule net N45305 (width 20)
rule net 3.3V (width 25)
rule net N56544 (width 20)
rule net N56552 (width 20)
rule net N56548 (width 20)
rule net N56554 (width 20)
rule net N56546 (width 20)
rule net N56556 (width 20)
rule net N56550 (width 20)
rule net N45265 (width 15)
rule net N45185 (width 20)
rule net N56558 (width 20)
rule net 'ENABLE POWER5V' (width 20)
rule net '6A9V(PILE)' (width 25)
rule net 5V (width 25)
rule net XBEERESET (width 20)
rule net N88155 (width 25)
rule net N88127 (width 25)
rule net XBEEDIN (width 20)
rule net XBEEDOUT (width 20)
rule net CAPTEURRX (width 20)
rule net CAPTEURTX (width 20)
rule net N45221 (width 15)
rule net N61433 (width 25)
rule net N61405 (width 20)
rule net CELL8 (width 20)
rule net CELL7 (width 20)
rule net N81598 (width 20)
rule net N82912 (width 25)
rule net N83047 (width 25)

################################################################################
# SAMENET CLEARANCE RULES                                                      #
################################################################################
# rule assignments for PCB clearances                                          #
################################################################################
rule PCB (clearance -1 same_net (type wire_wire))
rule PCB (clearance -1 same_net (type wire_smd))
rule PCB (clearance -1 same_net (type wire_pin))
rule PCB (clearance -1 same_net (type wire_via))
rule PCB (clearance -1 same_net (type smd_smd))
rule PCB (clearance -1 same_net (type smd_pin))
rule PCB (clearance -1 same_net (type smd_via))
rule PCB (clearance -1 same_net (type pin_pin))
rule PCB (clearance -1 same_net (type pin_via))
rule PCB (clearance -1 same_net (type via_via))
rule PCB (clearance -1 same_net (type test_test))
rule PCB (clearance -1 same_net (type test_wire))
rule PCB (clearance -1 same_net (type test_smd))
rule PCB (clearance -1 same_net (type test_pin))
rule PCB (clearance -1 same_net (type test_via))
rule PCB (clearance 0 same_net (type area_wire))
rule PCB (clearance 0 same_net (type area_smd))
rule PCB (clearance 0 same_net (type area_area))
rule PCB (clearance 0 same_net (type area_pin))
rule PCB (clearance 0 same_net (type area_via))
rule PCB (clearance 0 same_net (type area_test))

rule PCB (clearance 5 same_net (type microvia_microvia))
set microvia_microvia same_net off
rule PCB (clearance 5 same_net (type microvia_thrupin))
set microvia_thrupin same_net off
rule PCB (clearance 5 same_net (type microvia_smdpin))
set microvia_smdpin same_net off
rule PCB (clearance 5 same_net (type microvia_thruvia))
set microvia_thruvia same_net off
rule PCB (clearance 5 same_net (type microvia_bbvia))
set microvia_bbvia same_net off
rule PCB (clearance 5 same_net (type microvia_wire))
set microvia_wire same_net off
rule PCB (clearance 5 same_net (type microvia_testpin))
set microvia_testpin same_net off
rule PCB (clearance 5 same_net (type microvia_testvia))
set microvia_testvia same_net off
rule PCB (clearance 5 same_net (type microvia_bondpad))
set microvia_bondpad same_net off
rule PCB (clearance 5 same_net (type microvia_area))
set microvia_area same_net off
rule PCB (clearance 8 same_net (type nhole_pin))
set nhole_pin same_net off
rule PCB (clearance 8 same_net (type nhole_via))
set nhole_via same_net off
rule PCB (clearance 8 same_net (type nhole_wire))
set nhole_wire same_net off
rule PCB (clearance 8 same_net (type nhole_area))
set nhole_area same_net off
rule PCB (clearance 8 same_net (type nhole_nhole))
set nhole_nhole same_net off
rule PCB (clearance 5 same_net (type bbvia_bbvia))
set bbvia_bbvia same_net off
rule PCB (clearance 5 same_net (type bbvia_thrupin))
set bbvia_thrupin same_net off
rule PCB (clearance 5 same_net (type bbvia_smdpin))
set bbvia_smdpin same_net off
rule PCB (clearance 5 same_net (type bbvia_thruvia))
set bbvia_thruvia same_net off
rule PCB (clearance 5 same_net (type bbvia_wire))
set bbvia_wire same_net off
rule PCB (clearance 5 same_net (type bbvia_area))
set bbvia_area same_net off
rule PCB (clearance 5 same_net (type bbvia_testpin))
set bbvia_testpin same_net off
rule PCB (clearance 5 same_net (type bbvia_testvia))
set bbvia_testvia same_net off
rule PCB (clearance 5 same_net (type bbvia_bondpad))
set bbvia_bondpad same_net off

################################################################################
# rule assignments for net clearances                                          #
################################################################################

################################################################################
# WIRING RULES                                                                 #
################################################################################

################################################################################
# rule assignments for pcb wiring                                              #
################################################################################
rule pcb (tjunction on)(junction_type all)
rule pcb (staggered_via on (min_gap 5))

################################################################################
# rule assignments for layer wiring                                            #
################################################################################

################################################################################
# rule assignments for net wiring                                              #
################################################################################
################################################################################
# VIA_AT_SMD RULES                                                            #
################################################################################
rule pcb (via_at_smd off)
rule PCB (turn_under_pad off)

################################################################################
# PROPERTIES                                                                   #
################################################################################
