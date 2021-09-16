/*
==========================================================================================
Name        : ASM-commerce
Author      : Emanuele Perico
Version     : 1.0
Description : The scenario chosen for this project is that of an e-commerce:
			  making use of Abstract State Machine, it is shown a small example
			  for managing the status of an order for a company.
==========================================================================================
*/

asm project

import StandardLibrary

signature:
	// Domains declaration
	domain IdArticle subsetof Integer
	domain IdCustomer subsetof Integer
	enum domain Shipping = {COURIER1 | COURIER2}
	enum domain State = {BEGIN | CHECK_AID | CHECK_CID | CHOOSE_ART | INSERT_CID | INVOICE_CHEAP | INVOICE_EXP | ORDER_CONFIRMATION | SHIPMENT}
	// Functions declaration
	dynamic controlled currArtID: Integer
	dynamic controlled currCustID: Integer
	dynamic controlled currState: State
	dynamic controlled msg: String
	dynamic monitored input: Integer
	dynamic monitored shippingChoice: Shipping
	static isValidArtID: Integer -> Boolean
	static isValidCustID: Integer -> Boolean

definitions:
	// Domains definition
	domain IdCustomer = {001, 202, 384, 567, 999}
	domain IdArticle = {99001, 99002, 99003, 99004, 99005}

	// Functions definition
	function isValidArtID($id in Integer) =
		if(exist $a in IdArticle with $a = $id) then
			true
		else
			false
		endif

	function isValidCustID($id in Integer) =
		if(exist $c in IdCustomer with $c = $id) then
			true
		else
			false
		endif

	// Rules definition
	macro rule r_insertCustID =
		if(currState = INSERT_CID) then
			par
				currCustID := input
				currState := CHECK_CID
				msg := "Checking your CustomerID..."
			endpar
		endif

	macro rule r_checkCustID =
		if(currState = CHECK_CID) then
				if(isValidCustID(currCustID)) then
					par
						currState := CHOOSE_ART
						msg := "You are a registered customer! Choose an article now."
					endpar
				else
					par
						currState := BEGIN
						msg := "CustomerID does not exist!"
					endpar
				endif
		endif

	macro rule r_choice =
		if(currState = CHOOSE_ART) then
			par
				currArtID := input
				currState := CHECK_AID
				msg := "Checking the ArticleID..."
			endpar
		endif

	macro rule r_checkArtID =
		if(currState = CHECK_AID) then
				if(isValidArtID(currArtID)) then
					par
						currState := ORDER_CONFIRMATION
						msg := concat("Order confirmation for article: ", toString(currArtID))
					endpar
				else
					par
						currState := CHOOSE_ART
						msg := "ArticleID does not exist! Please choose it again."
					endpar
				endif
		endif

	macro rule r_ordConf =
		if(currState = ORDER_CONFIRMATION) then
			par
				currState := SHIPMENT
				msg := "Please choose a shipping method."
			endpar
		endif

	macro rule r_ship =
		if(currState = SHIPMENT) then
			par
				if(shippingChoice = COURIER1) then
					par
						msg := "Fast shipment selected. Additional costs added."
						currState := INVOICE_EXP
					endpar
				endif
				if(shippingChoice = COURIER2) then
					par
						msg := "Slow shipment selected. Costs included."
						currState := INVOICE_CHEAP
					endpar
				endif
			endpar
		endif

	macro rule r_invExp =
		if(currState = INVOICE_EXP) then
			par
				msg := "Here is your invoice (expensive). Thanks!"
				currState := BEGIN
			endpar
		endif

	macro rule r_invCheap =
		if(currState = INVOICE_CHEAP) then
			par
				msg := "Here is your invoice (cheap). Thanks!"
				currState := BEGIN
			endpar
		endif

	// Main rule
	main rule r_Main =
		if(currState = BEGIN) then
			par
				currState := INSERT_CID
				msg := "Welcome to our shop, please give us your CustomerID."
			endpar
		else
			par
				r_insertCustID[]
				r_checkCustID[]
				r_choice[]
				r_checkArtID[]
				r_ordConf[]
				r_ship[]
				r_invExp[]
				r_invCheap[]
			endpar
		endif

// Initial state
default init s0:
	function currState = BEGIN
