---------------------------------------------------------------------------------------------------
Contents of the COOLL dataset:
---------------------------------------------------------------------------------------------------
1) Meta data
	1.1) appliances_and_action_delays.txt
	1.2) license.txt
	1.3) README.txt
	1.4) scaleFactors.txt
	1.5) Configs.zip
	1.6) Headers.zip
2) Data
---------------------------------------------------------------------------------------------------
Contents details:
---------------------------------------------------------------------------------------------------
1) Meta data
---------------------------------------------------------------------------------------------------
	1.1) appliances_and_action_delays.txt:
	
	This file gives the measured appliance name and the corresponding action delay of each measurement instance in the form: [measurement_id]: [appliance_name_and_id]_[action_delay]ms

	This information may be retreived from the configuration files (see section 1.5 about the Configs.zip) 
---------------------------------------------------------------------------------------------------
	1.2) license.txt:
	
	The data is public provided for free non-commercial use under the Creative Commons Attribution-NonCommercial 4.0 International Public License
---------------------------------------------------------------------------------------------------
	1.3) README.txt: 
	
	The present file describing the contents of the COOLL dataset.
---------------------------------------------------------------------------------------------------
	1.4) scaleFactors.txt:	

	A file containing current and voltage scaling factors that allow the user to recover the real amplitude of all 840 measurement instances. The first column represents the current scaling factors and the second one the voltage scaling factors. The line number (from 1 to 840) represent the measurement id. After scaling, the current amplitude is in "Amps" and the voltage amplitude in "Volts".
---------------------------------------------------------------------------------------------------
	1.5) Configs.zip:

	Contains 840 ".txt" files (scenario1_1.txt to scenario1_840.txt). These files contain details about the measurement configuration and scenario (chosen outlets on the measurement system and measured appliances, pre-trigger duration, action delays, ...).

	File name convention:
		scenario[number_of_measured_appliances]_[measurement_id].txt

		- number_of_measured_appliances: an integer number from 1 to 6 (for COOLL it is always 1)
		- measurement_id: an integer number from 1 to 840 representing the measurement identification number
---------------------------------------------------------------------------------------------------	
	1.6) Headers.zip:

	Contains 42 ".xlsx" files containing informations about the 42 measured appliances (type, nominal power, ...)
---------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------
2) Data
---------------------------------------------------------------------------------------------------
	Contains 1680 ".flac" files (scenarioC1_1.flac to scenarioC1_840.flac and scenarioV1_1.flac to scenarioV1_840.flac) representing current and voltage measurements coded using the "free lossless audio codec (flac)" format. To avoid very large file size downloads, the files are put in 8 different ".zip" files (4 for current and 4 for voltage) of around 100 MB each.

	File name convention:
		scenario[measurement_type][number_of_measured_appliances]_[measurement_id].flac

		- measurement_type: either "C" for current or "V" for voltage
		- number_of_measured_appliances: an integer number from 1 to 6 (for COOLL it is always 1)
		- measurement_id: an integer number from 1 to 840 representing the measurement identification number

	IMPORTANT: the amplitude of the data contained in these files is scaled to range between -1 and 1 (a constraint due to the coding process). The user must use the "scaleFactors.txt" file to recover the real amplitude of the data (see section 1.4).
---------------------------------------------------------------------------------------------------



