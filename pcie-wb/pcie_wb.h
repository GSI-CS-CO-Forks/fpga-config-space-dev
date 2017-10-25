#ifndef PCIE_WB_DRIVER_H
#define PCIE_WB_DRIVER_H

#include "wishbone.h"

#define PCIE_WB "pcie_wb"
#define PCIE_WB_VERSION	"0.1"

#define PCIE_WB_VENDOR_ID	0x10dc
#define	PCIE_WB_DEVICE_ID	0x019a  // PCIe FTRNs (PEXARIA, EXPLODER, AMC)
#define	PMC_WB_DEVICE_ID	0xc570  // PMC  FTRN


#define CONTROL_REGISTER_HIGH	0  //0x00
#define CONTROL_REGISTER_LOW	4  //0x04
#define ERROR_FLAG_HIGH		8  //0x08
#define ERROR_FLAG_LOW		12 //0x0C
#define WINDOW_OFFSET_HIGH	16 //0x10
#define WINDOW_OFFSET_LOW	20 //0x14
#define SDWB_ADDRESS_HIGH	24 //0x18
#define SDWB_ADDRESS_LOW	28 //0x1C

#define PMC_IRQ_CONTROL         32 //0x20

#define MASTER_CTL_HIGH		64 //0x40
#define MASTER_CTL_LOW		68 //0x44
#define MASTER_ADR_HIGH		72 //0x48
#define MASTER_ADR_LOW		76 //0x4C
#define MASTER_DAT_HIGH		80 //0x50
#define MASTER_DAT_LOW		84 //0x54

#define WINDOW_HIGH	0xFFFF0000UL
#define WINDOW_LOW	0x0000FFFCUL

/* PCI core control and status registers in BAR0 */

#define PCI_STATUS_REG      0x04
#define PCI_CONF_IRQ        0x3C

#define WB_CONF_IRQ_STATUS_MASK 0x00000001

#define WB_CONF_INT_ACK_REG 0x1E8 /* PCI core WB interrupt Acknowledge register */    
#define WB_CONF_ICR_REG     0x1EC /* PCI core WB interrupt Control register */    
#define WB_CONF_ISR_REG     0x1F0 /* PCI core WB interrupt Status  register */


/* One per BAR */
struct pcie_wb_resource {
	unsigned long start;			/* start addr of BAR */
	unsigned long end;			/* end addr of BAR */
	unsigned long size;			/* size of BAR */
	void *addr;				/* remapped addr */
};

/* One per physical card */
struct pcie_wb_dev {
	struct pci_dev* pci_dev;
	struct pcie_wb_resource pci_res[3];
	int    msi;
	
	struct wishbone wb;
	unsigned int window_offset;
	unsigned int low_addr, width, shift;
};

#endif
