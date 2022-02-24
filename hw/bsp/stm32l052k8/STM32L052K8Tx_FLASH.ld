/* Linker script for STM32L052K8 */

ENTRY(Reset_Handler)

/* Specify the end of RAM as the end of the stack */
_estack = 0x20002000;

/* Specify a minimum heap and stack size. We do some math to ensure we have
 * sufficient left-over RAM after the program is loaded. */
_Min_Heap_Size = 0x280;
_Min_Stack_Size = 0x200;

/* There are just two memory regions, FLASH and RAM */
MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
	RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
	/* Make sure vector table goes in first in FLASH */
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP (*(.isr_vector)) /* Always make sure this section is here */
		. = ALIGN(4);
	} >FLASH

	/* The program code and other data goes into FLASH */
	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text*)
		*(.glue_7)         /* glue arm to thumb code */
		*(.glue_7t)        /* glue thumb to arm code */
		*(.eh_frame)

		KEEP (*(.init))
		KEEP (*(.fini))

		. = ALIGN(4);
		_etext = .;
	} >FLASH

	/* Keep constants in FLASH */
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} >FLASH

	/* ARM unwinding structures */
	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} >FLASH

	.ARM : {
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} >FLASH

	/* C/C++ initialization code */
	.preinit_array :
	{
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array*))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	} >FLASH

	.init_array :
	{
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array*))
		PROVIDE_HIDDEN (__init_array_end = .);
	} >FLASH

	.fini_array :
	{
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(SORT(.fini_array.*)))
		KEEP (*(.fini_array*))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} >FLASH

	/* Location of data to be loaded to RAM */
	_sidata = LOADADDR(.data);

	/* Data to be copied to RAM from FLASH */
	.data : 
	{
		. = ALIGN(4);
		_sdata = .;        /* create a global symbol at data start */
		*(.data)           /* .data sections */
		*(.data*)          /* .data* sections */

		. = ALIGN(4);
		_edata = .;        /* define a global symbol at data end */
	} >RAM AT >FLASH

	/* The imfamous BSS section... uninitialized data */
	. = ALIGN(4);
	.bss :
	{
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		_ebss = .;
		__bss_end__ = _ebss;
	} >RAM

	/* Check that there's enough RAM for min stack and heap */
	._user_heap_stack :
	{
		. = ALIGN(8);
		PROVIDE ( end = . );
		PROVIDE ( _end = . );
		. = . + _Min_Heap_Size;
		. = . + _Min_Stack_Size;
		. = ALIGN(8);
	} >RAM

	/* Get rid of any sections from standard libraries not used elsewhere */
	/DISCARD/ :
	{
		libc.a ( * )
		libm.a ( * )
		libgcc.a ( * )
	}

	/* Build attributes */
	.ARM.attributes 0 : { *(.ARM.attributes) }
}
