/* generated configuration header file - do not edit */
#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_

#define BSP_CFG_CLOCKS_SECURE   (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)
#define BSP_CFG_XTAL_HZ         (24000000)                         /* XTAL 24000000Hz */
#define BSP_CFG_HOCO_FREQUENCY  (2)                                /* HOCO 20MHz */
#define BSP_CFG_PLL_SOURCE      (BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC) /* PLL Src: XTAL */
#define BSP_CFG_PLL_DIV         (BSP_CLOCKS_PLL_DIV_3)             /* PLL Div /3 */

#ifdef TRACE_ETM
// Due to ozone fixed trace clock div = 1, PLL is limited around 100Mhz. This use 128 Mhz
#define BSP_CFG_PLL_MUL         (BSP_CLOCKS_PLL_MUL(16U,0U))       /* PLL Mul x16.0 */
#else
#define BSP_CFG_PLL_MUL         (BSP_CLOCKS_PLL_MUL(25U,0U))       /* PLL Mul x25.0 */
#endif

#define BSP_CFG_PLL2_SOURCE     (BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC) /* PLL2 Src: XTAL */
#define BSP_CFG_PLL2_DIV        (BSP_CLOCKS_PLL_DIV_2)             /* PLL2 Div /2 */
#define BSP_CFG_PLL2_MUL        (BSP_CLOCKS_PLL_MUL(20U,0U))       /* PLL2 Mul x20.0 */
#define BSP_CFG_CLOCK_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL)      /* Clock Src: PLL */
#define BSP_CFG_CLKOUT_SOURCE   (BSP_CLOCKS_CLOCK_DISABLED)        /* CLKOUT Disabled */
#define BSP_CFG_UCK_SOURCE      (BSP_CLOCKS_SOURCE_CLOCK_PLL2)     /* UCLK Src: PLL2 */
#define BSP_CFG_U60CK_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL2)     /* U60CK Src: PLL2 */
#define BSP_CFG_OCTA_SOURCE     (BSP_CLOCKS_CLOCK_DISABLED)        /* OCTASPICLK Disabled */
#define BSP_CFG_CANFDCLK_SOURCE (BSP_CLOCKS_CLOCK_DISABLED)        /* CANFDCLK Disabled */
#define BSP_CFG_CECCLK_SOURCE   (BSP_CLOCKS_CLOCK_DISABLED)        /* CECCLK Disabled */
#define BSP_CFG_ICLK_DIV        (BSP_CLOCKS_SYS_CLOCK_DIV_1)       /* ICLK Div /1 */
#define BSP_CFG_PCLKA_DIV       (BSP_CLOCKS_SYS_CLOCK_DIV_2)       /* PCLKA Div /2 */
#define BSP_CFG_PCLKB_DIV       (BSP_CLOCKS_SYS_CLOCK_DIV_4)       /* PCLKB Div /4 */
#define BSP_CFG_PCLKC_DIV       (BSP_CLOCKS_SYS_CLOCK_DIV_4)       /* PCLKC Div /4 */
#define BSP_CFG_PCLKD_DIV       (BSP_CLOCKS_SYS_CLOCK_DIV_2)       /* PCLKD Div /2 */
#define BSP_CFG_BCLK_DIV        (BSP_CLOCKS_SYS_CLOCK_DIV_2)       /* BCLK Div /2 */
#define BSP_CFG_BCLK_OUTPUT     (2)                                /* EBCLK Div /2 */
#define BSP_CFG_FCLK_DIV        (BSP_CLOCKS_SYS_CLOCK_DIV_4)       /* FCLK Div /4 */
#define BSP_CFG_CLKOUT_DIV      (BSP_CLOCKS_SYS_CLOCK_DIV_1)       /* CLKOUT Div /1 */
#define BSP_CFG_UCK_DIV         (BSP_CLOCKS_USB_CLOCK_DIV_5)       /* UCLK Div /5 */
#define BSP_CFG_U60CK_DIV       (BSP_CLOCKS_USB60_CLOCK_DIV_4)     /* U60CK Div /4 */
#define BSP_CFG_OCTA_DIV        (BSP_CLOCKS_OCTA_CLOCK_DIV_1)      /* OCTASPICLK Div /1 */
#define BSP_CFG_CANFDCLK_DIV    (BSP_CLOCKS_CANFD_CLOCK_DIV_1)     /* CANFDCLK Div /1 */
#define BSP_CFG_CECCLK_DIV      (BSP_CLOCKS_CEC_CLOCK_DIV_1)       /* CECCLK Div /1 */


#endif /* BSP_CLOCK_CFG_H_ */
