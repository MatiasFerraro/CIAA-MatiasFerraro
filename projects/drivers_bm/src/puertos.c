/*
 * puertos.c
 *
 *  Created on: 01/01/2016
 *  Author: Matias Leandro Ferraro
 */
#include "puertos.h"

int port_pin(uint8_t puerto, uint8_t pin, uint8_t config ,uint8_t modo)
{
#define init_in  0
#define init_out 1
#define high     2
#define low      3
#define state_in 4

switch(puerto)
{
case  0: if ((pin==0)||(pin==1))
   {
     switch(pin)
	 {
       case 0:
       case 1:	switch(modo)
				{
				 case init_in:
				 case init_out:{Chip_SCU_PinMux(0,pin,config,FUNC0);
							    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, pin, modo);
							   }break;
                 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, pin);
						   }break;

				 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, pin);
						   }break;
				 case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, pin);
								}break;
				}break;
	 }
	 }break;
case  1: if (((pin>0)&&(pin<18))||(pin==20)||(pin==0)||(pin==18))
   {
    switch(pin)
	{
		case 0:switch(modo)
			   {
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 4,modo);
							  }break;
				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 4);
                          }break;
                case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 4);
                          }break;
                case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4);
                               }break;
               }break;
		case 1:
		case 2:
		case 3:
		case 4:switch(modo)
			   {
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, pin+7, modo);
							  }break;
                case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, pin+7);
						  }break;
                case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, pin+7);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, pin+7);
							   }break;
               }break;
		case 5:
		case 6:switch(modo)
			   {
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, pin+3,modo);
							  }break;
                case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, pin+3);
						  }break;
                case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, pin+3);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, pin+3);
								}break;
			   }break;
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:switch(modo)
				{
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, pin-7,modo);
							  }break;

				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1,pin-7);
						  }break;

				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, pin-7);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, pin-7);
							   }break;
				}break;
		case 15:
		case 16:switch(modo)
		        {
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, pin-13,modo);
							  }break;

				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, pin-13);
						  }break;

				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, pin-13);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, pin-13);
							   }break;
				}break;
		case 17:
		case 18:switch(modo)
				{
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC0);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, pin-5,modo);
							  }break;

				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, pin-5);
						  }break;

				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, pin-5);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, pin-5);
							   }break;
				}break;
		case 20:switch(modo)
				{
				case init_in :
				case init_out:{Chip_SCU_PinMux(1,pin,config,FUNC4);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 15,modo);
							  }break;

				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 15);
						  }break;

				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 15);
                          }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 15);
							   }break;
			 }break;
			}
		   }break;
case  2:if (((pin>0)&& (pin<6))||(pin==8)||(pin==0)||(pin==6))
   {
	switch(pin)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:switch(modo)
			   {
				case init_in :
				case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC4);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin, modo);
							  }break;

				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin);
						  }break;

				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin);
							   }break;
			   }break;
        case 8:switch(modo)
			   {
				case init_in :
				case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC4);
							   Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, 7,modo);
							  }break;
				case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 7);
						  }break;
				case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 7);
						  }break;
				case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, 7);
							   }break;
				}break;
				}break;
			    }
    if (((pin>9)&&(pin<13))||(pin==7)||(pin==9)||(pin==13))
	{
	switch(pin)
	{
		case 7:switch(modo)
				{
				 case init_in :
				 case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC0);
								Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0,  7,modo);
							   }break;

				 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 7);
						   }break;

				 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 7);
						   }break;
				 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 7);
								}break;
				}break;
		case 9:switch(modo)
				{
				 case init_in :
				 case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC0);
								Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1,  10,modo);
							   }break;
				 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 10);
						   }break;
				 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 10);
						   }break;
				 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 10);
								}break;
				}break;
		case 10:switch(modo)
				 {
				  case init_in :
				  case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC0);
								 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0,  14,modo);
								}break;
				  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14);
							}break;
				  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
							}break;
				  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 14);
								 }break;
				 }break;
		case 11:
		case 12:
		case 13:switch(modo)
				 {
				  case init_in :
				  case init_out:{Chip_SCU_PinMux(2,pin,config,FUNC0);
								 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, pin,modo);
								}break;
				  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, pin);
							}break;
				  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, pin);
							}break;
				  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, pin);
							     }break;
				}break;
		}break;
	}break;
case  3: if ((pin==1)||(pin==2)||(pin==7)||(pin==8))
   {
   switch(pin)
   {
		case 1:
		case 2:	switch(modo)
		   		 {
		   		  case init_in:
		   		  case init_out:{Chip_SCU_PinMux(3,pin,config,FUNC4);
		   						 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+7, modo);
		   						}break;
		          case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+7);
		   					}break;

		   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+7);
		   					}break;
		   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+7);
		   						 }break;
		   		 }
		case 7:
		case 8:	switch(modo)
		   		 {
		   		  case init_in:
		   		  case init_out:{Chip_SCU_PinMux(3,pin,config,FUNC4);
		   						 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+3, modo);
		   						}break;
		   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+3);
		   					}break;

		   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+3);
		   					}break;
		   		  case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+3);
		   						 }break;
		   		}
   }break;
   }
   if ((pin==4)||(pin==5)||(pin==6))
   {
   switch(pin)
   {
	    case 4:
		case 5:	switch(modo)
		   		 {
		   		  case init_in:
		   		  case init_out:{Chip_SCU_PinMux(3,pin,config,FUNC0);
		   				   		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 1, pin+10, modo);
		   				   		}break;
		   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, pin+10);
		   				   	}break;

		   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, pin+10);
		   				   	}break;
		   		  case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, pin+10);
		   				   		 }break;
		   		 }break;
		case 6:switch(modo)
		        {
			      case init_in:
			   	  case init_out:{Chip_SCU_PinMux(3,pin,config,FUNC0);
			   					 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 6, modo);
			   					}break;
			      case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 6);
			   				}break;

			   	  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 6);
			   				}break;
			   	  case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 6);
			   					 }break;
		        }break;
   }break;
   }break;
case  4: if (((pin>0)&&(pin<6))||(pin==0)||(pin==6))
   {
   switch(pin)
   {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:	switch(modo)
		  		 {
		  		  case init_in:
		  		  case init_out:{Chip_SCU_PinMux(4,pin,config,FUNC0);
		  		   				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 2, pin, modo);
		  		   				}break;
		  		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 2, pin);
		  		   			}break;

		  		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 2, pin);
		  		   			}break;
		  		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 2, pin);
		  		   				 }break;
		  	     }break;
   }break;
   }
   if ((pin==8)||(pin==9)||(pin==10))
   {
   switch(pin)
   {
		case 8:
		case 9:
		case 10: switch(modo)
		  		 {
		  		  case init_in:
		  		  case init_out:{Chip_SCU_PinMux(4,pin,config,FUNC4);
		  				  		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+4, modo);
		  				  		}break;
		  		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+4);
		  				  	}break;

		  		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+4);
		  				  	}break;
		  		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+4);
		  				  		 }break;
		  		 }break;
   }break;
   }break;
case  5: if (((pin>0)&&(pin<7))||(pin==0)||(pin==7))
   {
   switch(pin)
   {
	   	case 0:
	   	case 1:
	   	case 2:
	   	case 3:
	   	case 4:
	   	case 5:
	   	case 6: switch(modo)
	   		  	{
	   		  	 case init_in:
	   		  	 case init_out:{Chip_SCU_PinMux(5,pin,config,FUNC0);
	   		  				  	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 2, pin+9, modo);
	   		  				   }break;
	   		  	 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 2, pin+9);
	   		  			   }break;

	   		  	 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 2, pin+9);
	   		  			   }break;
	   		  	 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 2, pin+9);
	   		  				  	}break;
	   	        }break;
	    case 7: switch(modo)
	   		  	{
	   		  	 case init_in:
	   		  	 case init_out:{Chip_SCU_PinMux(5,pin,config,FUNC0);
	   		  		   		  	Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 2, 7, modo);
	   		  		   		   }break;
	   		  	 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 2, 7);
	   		  		   	   }break;

	   		  	 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 2, 7);
	   		  		   	   }break;
	   		  	 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 2, 7);
	   		  		   		  	}break;
	   		  	}break;

    }break;
   }break;
case  6: if ((((pin>1)&&(pin<6))||(pin==1)||(pin==6))||((pin>9)&&(pin<12))||(pin==9)||(pin==12))
   {
   switch(pin)
   {
	   	case 1:
	   	case 2:
	   	case 3:
	   	case 4:
	   	case 5:
	   	case 6: switch(modo)
	   	   		{
	   	   		 case init_in:
	   	   		 case init_out:{Chip_SCU_PinMux(6,pin,config,FUNC0);
	   	   		  				Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, pin-1, modo);
	   	   		  			   }break;
	   	   		 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3, pin-1);
	   	   		  		   }break;

	   	   		 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3, pin-1);
	   	   		  				  		   				}break;
	   	   		 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 3, pin-1);
	   	   		  				  		   					 }break;
	   	   		}break;
	   	case 7:
	   	case 8: switch(modo)
	   	   		{
	   	   		 case init_in:
	   	   		 case init_out:{Chip_SCU_PinMux(6,pin,config,FUNC4);
	   	   		  		   		Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+8, modo);
	   	   		  		   	   }break;
	   	   		 case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+8);
	   	   		  		   }break;

	   	   		 case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+8);
	   	   		  		   }break;
	   	   		 case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+8);
	   	   		  		   		}break;
	   	   		}break;
	   	case 9:
	   	case 10:
	   	case 11: switch(modo)
	   	   		 {
	   	   		  case init_in:
	   	   		  case init_out:{Chip_SCU_PinMux(6,pin,config,FUNC0);
	   	   			   	   		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, pin-4, modo);
	   	   			   	   		}break;
	   	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3, pin-4);
	   	   			   	   	}break;

	   	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3, pin-4);
	   	   			   	   	}break;
	   	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 3, pin-4);
	   	   			   	   		 }break;
	   	   		 }break;
	   	case 12: switch(modo)
	   	   		 {
	   	   		  case init_in:
	   	   		  case init_out:{Chip_SCU_PinMux(6,pin,config,FUNC0);
	   	   			   	   		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 2, 8, modo);
	   	   			   	   		}break;
	   	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 2, 8);
	   	   			   	   	}break;

	   	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 2, 8);
	   	   			   	   			   	   		  		}break;
	   	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 2, 8);
	   	   			   	   		 }break;
	   	   		 }break;
	   	 }break;
	}break;
case  7:  if (((pin>0)&&(pin<7))||(pin==0)||(pin==7))
   {
   switch(pin)
   {
	   	case 0:
	   	case 1:
	   	case 2:
	   	case 3:
	   	case 4:
	   	case 5:
	   	case 6:
	   	case 7: switch(modo)
	   		  	{
	   		  	  case init_in:
	   		  	  case init_out:{Chip_SCU_PinMux(7,pin,config,FUNC0);
	   		  				  	 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, pin+8, modo);
	   		  				  	}break;
	   		  	  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3, pin+8);
	   		  				}break;

	   		      case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3, pin+8);
	   		  				}break;
	   		  	  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 3, pin+8);
	   		  				  	 }break;
	   		  	}break;
   }break;
   }break;
case  8: if (((pin>0)&&(pin<7))||(pin==0)||(pin==7))
   {
   switch(pin)
   {
	   	case 0:
	   	case 1:
	   	case 2:
	   	case 3:
	   	case 4:
	   	case 5:
	   	case 6:
	   	case 7: switch(modo)
	   		 	{
	   		 	  case init_in:
	   		 	  case init_out:{Chip_SCU_PinMux(8,pin,config,FUNC0);
	   		 	   		  		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, pin, modo);
	   		 	   		  		}break;
	   		 	  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 3, pin);
	   		 	   		  	}break;

	   		 	  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 3, pin);
	   		 	   		  	}break;
	   		 	  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 3, pin);
	   		 	   		  		 }break;
	   		 	}break;
   }break;
   }break;
case  9: if (((pin>0)&&(pin<6))||(pin==0)||(pin==6))
   {
   switch(pin)
   {
	   	case 0:
	   	case 1:
	   	case 2:
	   	case 3: switch(modo)
	   	   		{
	   	   		  case init_in:
	   	   		  case init_out:{Chip_SCU_PinMux(9,pin,config,FUNC0);
	   	   		 	   		  	 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 4, pin+12, modo);
	   	   		 	   		    }break;
	   	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 4, pin+12);
	   	   		 	   		}break;

	   	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 4, pin+12);
	   	   		 	   		}break;
	   	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 4, pin+12);
	   	   		 	   		  	 }break;
	   	   	    }break;
	   	case 4:
	   	case 5: switch(modo)
	   	   		{
	   	   		  case init_in:
	   	   		  case init_out:{Chip_SCU_PinMux(9,pin,config,FUNC4);
	   	   		   	   		 	 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+13, modo);
	   	   		   	   		 	}break;
	   	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+13);
	   	   		            }break;

	   	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+13);
	   	   		   	   		}break;
	   	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+13);
	   	   		   	   		 	 }break;
	   	   		}break;
	    case 6: switch(modo)
	   	   		{
	   	   		  case init_in:
	   	   		  case init_out:{Chip_SCU_PinMux(9,pin,config,FUNC0);
	   	   		   	   		   	 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 4, 11, modo);
	   	   		   	   		   	 }break;
	   	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 4, 11);
	   	   		   	   		}break;

	   	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 4, 11);
	   	   		   	   		}break;
	   	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 4, 11);
	   	   		 }break;
	   	   	}break;
        }break;
	}break;
case 10: if (((pin>1)&&(pin<4))||(pin==1)||(pin==4))
   {
   switch(pin)
   {
	    case 1:
	    case 2:
	   	case 3:	switch(modo)
	   		   	{
	   		   	  case init_in:
	   		   	  case init_out:{Chip_SCU_PinMux(10,pin,config,FUNC0);
	   		   				   	 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 4, pin+7, modo);
	   		   				   	}break;
	   		   	  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 4, pin+7);
	   		   				}break;

	   		   	  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 4, pin+7);
	   		   				}break;
	   		   	  case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 4, pin+7);
	   		   				   	 }break;
	   		   	}break;
	   	case 4: switch(modo)
	   		    {
	   			  case init_in:
	   			  case init_out:{Chip_SCU_PinMux(10,pin,config,FUNC4);
	   			   				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, 19, modo);
	   			   				}break;
	   			  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 19);
	   			   			}break;

	   			  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 19);
	   			   			}break;
	   			  case state_in :{	return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, 19);
	   	}break;
      }break;
	}break;
}break;
case 11: if (((pin>0)&&(pin<6))||(pin==0)||(pin==6))
   {
   switch(pin)
   {
	    case 0:
	  	case 1:
	  	case 2:
	  	case 3:
	  	case 4:
	  	case 5:
	  	case 6: switch(modo)
	  	   		{
	  	   		  case init_in:
	  	   		  case init_out:{Chip_SCU_PinMux(11,pin,config,FUNC4);
	  	   		  				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 5, pin+20, modo);
	  	   		  				}break;
	  	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, pin+20);
	  	   		  				}break;

	  	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, pin+20);
	  	   		  			}break;
	  	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 5, pin+20);
	  	   		  				 }break;
	  	   		}break;
	}break;
}break;
case 12: if (((pin>1)&&(pin<14))||(pin==1)||(pin==14))
   {
   switch(pin)
   {
	    case 1:
	  	case 2:
	  	case 3:
	  	case 4:
	  	case 5:
	  	case 6:
	  	case 7:
	  	case 8:
	  	case 9:
	  	case 10:
	  	case 11:
	  	case 12:
	  	case 13:
	  	case 14: switch(modo)
	  	   		 {
	  	   		  case init_in:
	  	   		  case init_out:{Chip_SCU_PinMux(12,pin,config,FUNC4);
	  	   		  				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 6, pin-1, modo);
	  	   		  				}break;
	  	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 6, pin-1);
	  	   		  			}break;

	  	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 6, pin-1);
	  	   		  			}break;
	  	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 6, pin-1);
	  	   		  				 }break;
	  	   		 }break;
	  }break;
 }break;
case 13: if (((pin>0)&&(pin<16))||(pin==0)||(pin==16))
   {
   switch(pin)
   {
	    case 0:
	    case 1:
	  	case 2:
	  	case 3:
	  	case 4:
	  	case 5:
	  	case 6:
	  	case 7:
	  	case 8:
	  	case 9:
	  	case 10:
	  	case 11:
	  	case 12:
	  	case 13:
	    case 14:
	  	case 15:
	  	case 16: switch(modo)
	  	   		 {
	  	   		  case init_in:
	  	   		  case init_out:{Chip_SCU_PinMux(13,pin,config,FUNC4);
	  	   		  				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 6, pin+14, modo);
	  	   		  				}break;
	  	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 6, pin+14);
	  	   		  			}break;

	  	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 6, pin+14);
	  	   		  				  		   				}break;
	  	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 6, pin+14);
	  	   		  				 }break;
	  	   		 }break;
	}break;
}break;
case 14: if (((pin>0)&&(pin<15))||(pin==0)||(pin==15))
   {
   switch(pin)
   {
	    case 0:
	    case 1:
	  	case 2:
	  	case 3:
	  	case 4:
	  	case 5:
	  	case 6:
	  	case 7:
	  	case 8:
	  	case 9:
	  	case 10:
	  	case 11:
	    case 12:
	  	case 13:
	  	case 14:
	  	case 15: switch(modo)
	  	   		 {
	  	   		  case init_in:
	  	   		  case init_out:{Chip_SCU_PinMux(14,pin,config,FUNC4);
	  	   		  				 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 7, pin, modo);
	  	   		  				}break;
	  	   		  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 7, pin);
	  	   		  			}break;

	  	   		  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 7, pin);
	  	   		  			}break;
	  	   		  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 7, pin);
	  	   		  				 }break;
	  	   		 }break;
   }break;
}break;
case 15: if (((pin>1)&&(pin<3))||(pin==1)||(pin==3))
   {
   switch(pin)
   {
        case 1:
      	case 2:
      	case 3: switch(modo)
      	  	   	{
      	  	   	  case init_in:
      	  	   	  case init_out:{Chip_SCU_PinMux(115,pin,config,FUNC4);
      	  	   		  			 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 7, pin+15, modo);
      	  	   		  			}break;
      	  	   	  case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 7, pin+15);
      	  	   		  		}break;

      	  	   	  case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 7, pin+15);
      	  	   		  		}break;
      	  	   	  case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 7, pin+15);
      	  	   		  			 }break;
      	  	   	}break;
      	case 5:
      	case 6:
      	case 7:
      	case 8:
      	case 9:
      	case 10:
      	case 11: switch(modo)
      	  	     {
      	  	      case init_in:
      	  	      case init_out:{Chip_SCU_PinMux(15,pin,config,FUNC4);
      	  	      	  	   		 Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 7, pin+14, modo);
      	  	      	  	   		}break;
      	  	      case high:{Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 7, pin+14);
      	  	      	  	   	}break;

      	  	      case low :{Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 7, pin+14);
      	  	      	  	   	}break;
      	  	      case state_in :{return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 7, pin+14);
      	  	      	  	   		 }break;
      	  	     }break;


    }break;
  }break;
 }
}









