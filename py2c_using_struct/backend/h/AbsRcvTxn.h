
/************************* Header File Info ***************************************
*	File			: AbsRcvTxn.h
*	Application		: Automatic Betting System
*	Copyright		: Tata Consultancy Services
*	Authors			: Puresh Kumar K, Asha G
*	Creation Date	: 29th December 1998
*	Description		: This header file includes the structures sent by the server 
*		    			or structures received at the client for different
*						transactions in the Automatic Betting System (ABS) 
*
*************************************************************************************/

#if !defined (ABS_RCV_TXN_H) 
#define ABS_RCV_TXN_H



struct sRcvHeader {
		int			nTxnCd;
		int			nRetCd;
		int			nNumRecs;
		int			nTxnId;
		char		cBtMake;
};


struct sRcvRcm {
		char		cRaceDt[11];
		char		cRaceVenue[13];
};


struct sRcvMtm {
		char		cMoneyTyp;
		char		cMoneyTypDesc[31];
};


struct sRcvPmm {
		char		cPoolId[4];
		char		cPoolDesc[31];
		char		cLegTyp;
		int			nHorseOrRace;
		int			nMinRunners;
};


struct sRcvUmm {
		char		cUsrId[5];		
		char		cMagOpCd[17];
		char		cIROpCd[17];
		char		cUsrNm[31];
		char		cUsrTyp[5];
		char		cPwd[13];
};


struct  sRcvUmmNew {
	    char  cPermEmpCode[7];
    	char  cUsrId[5];
		char cUsrNm[31];
		char  cUsrTyp[5];
		char  cDtOfBirth[11];
		char  cAssignmentDt[11];
		char  cFOrHName[31];
		char cPFEligibility;
		char   cPFNominee[31];
        float  fSplAllowance;
        float  fExtraAllowance;
};



struct sRcvPfm {
		char   cPermEmpCode[7];
		char   cPFNumber[14];
		char   cWorkedFromDt[11];
		char   cWorkedToDt[11];
		float  fPFPercentage;
		float  fFPPercentage;
};

struct sRcvUtm {
		char		cUsrTyp[5];
		char		cUsrDesc[31];		
		float		fOnCourse9;
		float		fOnCourse10;
		float		fOnCourse11;
		float		fOnCourse12;		
		float		fOffCourse9;
		float		fOffCourse10;
		float		fOffCourse11;
		float		fOffCourse12;
		float		fFoodAllowance;
		float		fAttendanceIncentive;		
};


struct sRcvTmm {
		char		cTxnCd[4];
		char		cTxnDesc[31];
};


struct sRcvBtmMst {
		char		cBtId[5];
		char		cTermTyp;
		char		cBtNm[31];
		char		cEnclCd[5];
		char		cGrpCd[4];
		char		cCableCd[5];
		char		cBtSts;
		char		cOpCardTyp;
		char		cBtMake;
		char		cBtMode;
		char		cMoneyTyp[4];
		float		fMinSaleBet;
		float		fMaxSaleBet;
		float		fPayMaxAmt;
};


struct sRcvBtmDtl {
		char		cDtlTyp;
		char		cPoolOrVenue[4];
		char		cDtlSts;
};


struct sRcvVmm {
		char		cRaceVenue[4];
		char		cVenueNm[31];		
		char		cInchargeNm[31];
		char		cAddress1[31];
		char		cAddress2[31];
		char		cAddress3[31];
		char		cAddress4[31];		
};


struct sRcvCar {
		char		cRaceNum[3];
};


struct sRcvWhr {
		char		cRaceNum[3];
		char		cHorseNum[3];
};


struct sRcvCav {
		char		cRaceDt[11];
		char		cRaceVenue[4];
};


struct sRcvGcm {
		char		cEnclCd[5];
		char		cGrpCd[4];
		char		cGrpNm[31];
		int			nPriority;
};


struct sRcvGrm {
		char		cGrdCd[3];
		char		cGrdNm[31];
		float		fGrdSalesSlab1;
		float		fGrdSalesSlab2;
};


struct sRcvCtr {		
		float		fCashAmt;
		float		fCashVoucherAmt;
		char		cUsrNm[31];
};


struct sRcvRtr {
		char		cVoucherNum[17];
		float		fAmt;
		char		cUsrNm[31];
};


struct sRcvPyt {
		float		fCashAmt;
		float		fCashVoucherAmt;
		float		fTdsAmt;
		char		cTdsNum[6];
		char		cUsrNm[31];
};


struct sRcvEnm {
		char		cEnclCd[5];
		char		cEnclNm[31];
};


struct sRcvIrpMst1 {
		char		cRaceDt[11];
		char		cRaceVenue[4];
		int			nNumOfRaces;
		int			nSLGPools;
		int			nMLGPools;
		char		cAdvertisement[41];
};

//Race card
struct sRcvIrpDtl1 {
		char		cRaceNum[3];
		char		cRaceStartTime[9];
		int			nNumOfHorses;

};


struct sRcvIrpDtl2 {
		char		cRaceNum[3];
		char		cPools[4];
		char		cCombinedOperFlg;
		char		cVenueCnt;
		char		cVenues[28];
};


struct sRcvIrpDtl3 {
		char		cRaceNum[3];
		char		cMultiLegPools[4];
		char		cCombinedOperFlg;
		char		cSelectRaceNum[11];
		char		cVenueCnt;
		char		cVenues[28];
};


struct sRcvBELog {
		char		cDateTime[20];
		char		cUsrNm[31];
		char		cUsrId[5];
		char		cUsrTyp[5];
		char		cBtTyp[3];
};


struct sRcvLog {
		char		cDateTime[20];
        char        cUsrNm[31];
        char        cUsrId[5];
        char        cSupNm[31];
        char        cSupId[5];
        char        cUsrTyp[5];
        float       fOpenBal;
        float       fTktSalesByVoucher;
        float       fTktSalesByCash;
        float       fTktSalesByMemCard;
        int         nTktSalesByVoucherCount;
        int         nTktSalesByCashCount;
        int         nTktSalesByMemCardCount;
        float       fPayoutByVoucher;
        float       fPayoutByCash;
        float       fPayoutByMemCard;
		int         nPayoutByVoucherCount;
		int         nPayoutByCashCount;
        int         nPayoutByMemCardCount;
        float       fCancelByVoucher;
        float       fCancelByCash;
        float       fCancelByMemCard;
		int         nCancelByVoucherCount;
		int         nCancelByCashCount;
		int         nCancelByMemCardCount;
        float       fDeposit;
        float       fWithdrawAmt;
        float       fVoucherSales;
		float       fVoucherEncash;
		float       fCloseBal;
		float		fSaleTarget;
};


struct sRcvRpi1 {	
		int			nRaceDt;
		char		cVenueNum;
		char		cVenueSts;
		char		cRaces[15];
		char		cAdvertisement[41];
};


struct sRcvRpi2 {
		int			nRaceDt;
		char		cVenueNum;
	    char		cRaceNum;
		char		cHorses[25];
		int			nRaceStartTm;
};


struct sRcvRpi3 {
		int			nRaceDt;
		char		cVenueNum;
		char		cRaceNum;
		char		cPools[9];
};


struct sRcvRpi4 {
		int			nRaceDt;
		char		cVenueNum;
		char		cRaceNum[3];
		char		cSelectRaceNum[11];
		char		cPoolSts;
};


struct sRcvRsr {
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
		char		cStopbetSts;
};


struct sRcvVnuBtn {		
		char		cPayDt[11];
		char		cChkDt[11];
		char		cChkNum[7];
		float		fChkAmt;
		char		cFromDt[11];
		char		cToDt[11];
		char		cFromVenue[4];
		char		cToVenue[4];
		char		cRemarks[31];
};


struct sRcvPntBtn {		
		char		cPayDt[11];
		char		cChkDt[11];
		char		cChkNum[7];
		float		fChkAmt;
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
		char		cTktNum[17];
		char		cRemarks[31];

};


struct sRcvBtnTkt {
        char        cTktNum[17];
        float       fChkAmt;
        char        cRaceDt[11];
        char        cRaceVenue[4];
        char        cRaceNum[3];
};


struct sRcvTdm {			
		char		cTaxCd[4];
		float		fTaxSlab1;
		float		fTaxSlab2;
		float		fTaxRate;
		float		fSurcharge;
};


struct sRcvTdd {
		char		cTxnCd[4];
		char		cDeductCd[4];
		char		cRaceVenue[4];
		char		cPoolId[4];
};


struct sRcvTtd {
		char		cTxnCd[4];
		char		cTaxCd[4];
		char		cRaceVenue[4];
		char		cPoolId[4];
};


struct sRcvTua {
		char		cTxnCd[4];
		char		cUsrTyp[5];
};


struct sRcvIvn {
		char		cVoucherNum[17];
		char		cCvSts;
		float		fCvAmt;
		int			nCvBtId;
};


struct sRcvEvn {
		char		cVoucherNum[17];
		char		cSts;
		float		fVAmt;
};


struct sRcvCFwdMst {		
		char		cFromRaceDt[11];
		char		cFromRaceVenue[4];
		char		cFromRaceNum[3];
		char		cFromPoolId[4];
		float		fCFwdTotalAmt;
		float		fBalanceAmt;
};


struct sRcvCFwdDtl {		
		char		cCFwdToRaceDt[11];
		char		cCFwdToVenue[4];
		char		cCFwdToRaceNum[3];
		char		cCFwdPool[4];
		float		fCarryOvrAmt;
};


struct sRcvCFwdInitDtl {
		char		cRaceDt[11];
		char 		cRaceVenue[4];
		char		cRaceNum[3];
};


struct sRcvDbt {
        char        cEnclCd[5];
        char        cGrpCd[4];
        char        cBtId[5];
        char        cBtSts;
};


struct sRcvCma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];						
};


struct sRcvRdCma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];				
		char		cLastVoucher[17];
		float		fBalance;
		char		cFromDt[11];
		char		cToDt[11];
		char		cAcctSts;

};


struct sRcvWma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];				
		char		cVoucherNum[17];
		char		cTxnTyp;
		float		fMadAmt;

};


struct sRcvDma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];				
		char		cVoucherNum[17];
		char		cTxnTyp;
		float		fAmt;
};


struct sRcvGma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];				
		char		cVoucherNum[17];
		char		cTktNum[17];
		char		cTxnTyp;
		float		fAmt;

};


struct sRcvEma {
		char		cMemAcctNum[7];
		char		cMemAcctCardCode[17];				
		char		cLastVoucher[17];
		float		fBalance;
		char		cFromDt[11];
		char		cCFwdToDt[11];
		char		cAcctSts;
};


struct sRcvBua {
		char		cBtId[5];
		char		cGrpCd[4];
};


struct sRcvBwd {
		char		cVoucherNum[17];
		float		fAmt;
		char		cUsrNm[31];
		char		cSuNm[31];
};


struct sRcvIsr {
		float		fRemVoucherAmt;
};


struct sRcvIsrInit {
		float		fAmount;
		
};


struct sRcvBtb {
		char		cBtId[5];
        float       fOpenBal;
        float       fTktSalesByVoucher;
        float       fTktSalesByCash;
        float       fTktSalesByMemCard;
        int			nTktSalesByVoucherCount;
		int			nTktSalesByCashCount;
		int         nTktSalesByMemCardCount;
        float       fPayoutByVoucher;
        float       fPayoutByCash;
        float       fPayoutByMemCard;
		int         nPayoutByVoucherCount;
		int         nPayoutByCashCount;
		int         nPayoutByMemCardCount;
        float       fCancelByVoucher;
        float       fCancelByCash;
        float       fCancelByMemCard;
		int			nCancelByVoucherCount;
        int         nCancelByCashCount;
        int         nCancelByMemCardCount;
        float       fDeposit;
        float       fWithdrawAmt;
        float       fVoucherSales;
        float       fVoucherEncash;
        float       fCloseBal;
};


struct sRcvUga {
		char		cUsrId[5];
		char		cGrdCd[3];
		char        cUsrNm[31];

};


struct sRcvBta {
		char		cBtTyp[3];
		char		cBtId[5];

};


struct sRcvRrrMst {
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
};


struct sRcvRrrDtl {
		int			nPlaceNum;
		char		cHorseNum[3];
};


struct sRcvInitRrrMst {
		char		cRaceVenue[4];

};


struct sRcvInitRrrDtl {
		char		cRaceNum[3];
		char		cHorseNum[3];

};


struct sRcvBtiMst {
		char		cBtId[5];
		char		cBtName[31];
		char		cEnclCd[5];
		char		cGrpCd[4];
		char		cBtMode;
		char		cMoneyTyp[4];
		float		fMinSaleBet;
		float		fMaxSaleBet;
		float		fPayMaxAmt;
};


struct sRcvBtiDtl {
		char		cDtlTyp;			// can indicate whether it is a	pool or venue or betting facility
		char		cPoolOrVenue[4];
		char		cDtlSts;			// 1 - Allowed, 0 - Not Allowed
};


struct sRcvPvm {
		char		cRaceVenue[4];
		char		cPoolId[4];
		float		fUnitPrice;
		float		fTaxRate;
		float		fDeductRate;
		char		cRemarks	[31];


};


struct sRcvInitWhr {
		char		cRaceDt[11];

};


struct sRcvSatMst {	
		char		cEnclCd[5];
		char		cGrpCd[4];
		
};


struct sRcvSatDtl {	
		char		cEnclCd[5];
		char		cGrpCd[4];
		char		cBtId[5];
		float		fSaleTarget;
		
};


struct sRcvBtu {
		char		cRaceDt[11];
		char		cUsrTyp;
		char		cUsrId[5];
		char		cUsrGrdCd[3];
		char		cUsrNm[31];
		char		cBtId[5];
		char		cBtGrdCd[3];
		char		cEnclCd[5];
		char		cGrpCd[4];
		
};


struct 	sRcvWch{
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
		char		cPoolId[4];
		char		cWhiteConeSts;
		char        cValidPools[100];
		char        cCalcReleasePools[100]; 

};


struct sRcvWchInit {
		char		cRaceNum[3];
		char		cPoolId[4];
};



//	Query	structures	below



struct sRcvTdq {	
		char		cVenue[4];
		char		cRaceDt[11];
		char		cRaceNum[3];
		char		cBtId[5];
		float		fTotVal;
		char		cPayoutSts;
		char        cWho;
        char        cUsrId[5];
        char        cUsrNm[31];
        char        cCrtDt[11];
        char        cCrtTm[9];
};


struct 	sRcvTdq1 {
		char		cRaceNum[3]; 
		char		cPoolId[4];
		char		cHorseSeq[11];
		int			nUnits;
		float		fVal;
		char		cTktSts;
};


struct sRcvRpt {
		char		cMessage[100];
		char		cStatus;
};
		

struct sRcvBtq {
		char		cBtId[5];
		char		cPoolId[45];
		float		fOpenBal;
		float		fTktSalesByMemCard;
		float		fTktSalesByVoucher;
		float		fTktSalesByCash;
		float		fDeposit;
		float		fPayoutByMemCard;
		float		fPayoutByVoucher;
		float		fPayoutByCash;
		float		fCancelByMemCard;
		float		fCancelByVoucher;
		float		fCancelByCash;
		float		fWithdrawAmt;
		float		fVoucherSales;
		float		fVoucherEncash;
		float		fCloseBal;
		float		fMaxBet;
		float		fMinBet;
		char		cUsrNm[31];
		char		cBtMode;
};


struct sRcvAtmInitMst {
		char		cUsrId[5];
        char        cUsrNm[31];
        char        cUsrTyp[5];
        char        cUsrGrdCd[3];
        char        cSignInDt[11];
        char        cSignInTm[9];
};   


struct sRcvAtmInitDtl {
		char		cBtGrdCd[3];
        int         nTotalBTCnt;
	    int         nAssmtCnt;
};


struct sRcvAtm {
		char		cUsrId[5];
        char        cUsrNm[31];
        char        cUsrTyp[5];
        char        cBtId[5];
        char        cEnclNm[31];
        char        cGrpCd[4];
        char        cBtMode;
        char        cSignInDt[11];
        char        cSignInTm[9];
        char        cSignOutDt[11];
        char        cSignOutTm[9];
        float       fSalesTargetAmt;
};
 


struct sRcvItcProbable {
		char		cHorseNum[11];
		char		cPoolId[4];
		float		fDividend;
		char		cWinnerSts;
		int 		nTkts;
};


struct sRcvItcCollection {
		char		cPoolId[4];
		float		fCollection;
};


struct sRcvItcMultiLegPass {
		char		cPoolId[4];
		char		cRaceNum[3];
		int			nLegNum;
		int			nTkts;
};


struct sRcvItcCarryOver {
		char		cRaceNum[3];
		char		cPoolId[4];
		float		fAmt;
};


struct sRcvSMaxBtu {
		char		cUsrId[5];
		char		cBtId[5];
		char		cBtInUsrId[5];
};
		

struct sRcvBga {
		char		cBtId[5];
		char		cGrdCd[3];
		char		cBtAssmtSts;
};


struct sRcvNhr {
        char        cRaceDt[11];
        char        cRaceVenue[4];
        char        cRaceNum[3];
        char        cHorseNum[3];
};


struct sRcvStb{
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
		char		cStartBetSts;
};


struct sRcvCap {
        char        cRaceDt[11];
        char        cRaceVenue[4];
};


struct sRcvCapDtl {
        char        cRaceNum[3];
        char        cPoolId[4];
};


struct sRcvDtn {
		char		cTxnCd[4];
		char        cTxnDesc[31];
		char        cTxnSts;
};


struct sRcvSunrayBtu {
		char		cBtId[5];		
		char		cBtMode;	
		float		fMinSaleBet;		
		float		fPayMaxAmt;
		float		fOpenBal;
};


struct sRcvItcLog {
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
		char		cPoolId[4];
};


//Ticket Issued Query Data Received
struct sRcvTcq {
        char        cTktNum[17];
        char        cRaceVenue[4];
        char        cRaceNum[3];
        float       fTktVal;
        char        cTktSts;
};


struct sRcvTcqCancel {
        char        cTktNum[17];
        char        cTktSts;
        char        cTktTyp;
        float       fTktVal;
        char        cBetCentre[4];
        char        cBetInfo[101];
};


struct sRcvTpqSusp {
        char        cTktNum[17];
        char        cTktSts;
        char        cTktTyp;
        float       fInvVal;
        float       fAmtPayable;
        char        cTktExpDt[11];
        char        cBetCentre[4];
        char        cBetInfo[101];
};


struct sRcvTsqDtl1 {
        char        cRaceDt[11];
        char        cRaceVenue[4];
        char        cRaceNum[3];
};


struct sRcvTsqDtl2 {
        char        cEnclCd[5];
        char        cBtId[5];
};


struct sRcvTsqDtl3 {
        char        cHorseNum[11];
};


struct sRcvDbtDtl1 {
	    char        cCableCd[5];
        char        cBtId[5];
        char        cBtSts;
};

 
struct sRcvDbtDtl2 {
        char        cCableCd[5];
};


struct sRcvCbm {
		char        cCableCd[5];        
};


struct sRcvVsq {
        char        cRaceVenue[4];
        char        cRaceNum[3];
        char        cPoolId[4];
        char        cBetCentre[4];
};


struct sRcvVsqDtl {
        char        cBetCentre[4];
        char        cFileTyp[4];
        char        cFileSts;
        char        cCrtTm[9];
};


struct sRcvVsqDtl1 {
		int 		nLegNum;
		char 		cHorseNum[11];
		char		cBetCentre[4];
		int 		nUnits;
		float		fAmt;
};


struct sRcvVsd {
        char        cRaceVenue[4];
        char        cRaceNum[3];
        char        cPoolId[4];
};

struct sRcvPHdr {
        char        cBetCentre[4];
        int         nUnits;
        float       fValueBased;
        float       fPoolrev;
        float       fDeductVal;
        float       fTaxVal;
        char        cSts;
};


struct sRcvPDtl {
        char        cRaceHorseNum[11];
        char        cBetCentre[4];
        float       fTotalRev;
        float       fValueBased;
        float       fHorseRev;
        int         nUnits;
        char        cHorseSts;
};


struct sRcvTsqWin {
        int         numResults;
        char        cRaceHorseNum[5][11];
};


struct sRcvCdqInit {
      char     cRaceDt[11];
      char     cRaceVenue[4];
      char     cRaceNum[3];
};


struct sRcvCdqInitDtl {
      char     cBtId[5];
};


struct sRcvCdqInitDtl1 {
	  char 		cUsrId[5];	
};


struct sRcvCdqDtl1 {
      char     cTktNum[17];
      char     cTktTyp;
      float    fTktVal;
};

struct sRcvCdqDtl2 {
      char     cTktNum[17];
      char     cTktTyp;
      float    fTktVal;
      char     cCrtBtId[5];
      char     cCrtUsrId[5];
      char     cCrtDt[11];
      char     cCrtTm[9];
};


struct  sRcvTdq2 {
        char        cTktTyp;
        char        cBetInfo[321];
        float       fTktVal;
        char        cTktSts;
        char        cBetCentre[4];
};


struct sRcvPrqDtl1 {
		char 		cPoolId[4];
		char 		cBetCentre[4];
};


struct sRcvPrqDtl2 {
		int 		nUnits;
		int 		nCancelledUnits;
		int 		nRefundUnits;
		float 		fPoolrev;
		float 		fDeductVal;
		float 		fTaxVal;
};


struct sRcvPrqDtl3 {
		char 		cRaceHorseNum[11];
		float 		fTotalRev;
		float 		fValueBased;
		float 		fHorseRev;
		int 		nUnits;
		char 		cHorseSts;
};


struct sRcvPdq {
		char 		cPoolId[4];
		char 		cBetCentre[4];
};


struct sRcvPdqDtl {
		char 		cRaceHorseNum[11];
		char 		cBetCentre[4];
		int 		nWinningUnits;
		float 		fInvVal;
		float 		fDeductVal;
		float 		fTaxVal;
		float 		fDividend;
};


//Race card
struct sRcvRcqDtl1 {
		char 		cStopbetSts;
		char 		cRaceSts;
		char 		cVenueSts;
		char 		cRaceStartTm[9];
        char        cCrtTm[9];
};


struct sRcvRcqDtl2 {
		char 		cHorseNum[3];
		char 		cHorseSts;
        char        cCrtTm[9];
};


struct sRcvRcqDtl3 {
		char 		cPoolId[4];
		char 		cBetCentre[4];
		float 		fUnitBtAmt;
		char 		cPoolSts;
		char 		cBetCentreSts;
		char 		cFinalSts;
		char 		cPayoutFileSts;
		char 		cPaymentReleasedSts;
};


struct sRcvRcqDtl4 {
		char 		cRaceNum[3];
};


struct sRcvLoqInit {
        char        cUsrTyp[5];
        char        cUsrDesc[31];
};


struct sRcvLoq {
        char        cBtId[5];
        char        cUsrId[5];
        char        cUsrNm[31];
        char        cTxnFlag;
        char        cTimeStamp[9];
};


struct sRcvLoqSign {
        char        cUsrId[5];
        char        cUsrNm[31];
        char        cSignInTm[9];
        char        cSignOutTm[9];
};


struct sRcvRrqInit {
        char        cRaceDt[11];
        char        cRaceVenue[4];
        char        cRaceNum[3];
};


struct sRcvRrq {
        char        cPoolId[4];
        char        cRaceHorseNum[11];
        float       fDivPercentage;
        float       fDivValue;
};


struct sRcvTsq {
        int         nUnits;
        float       fPoolrev;
        float       fDeductVal;
        float       fTaxVal;
        float       fValueBased;
};


struct sRcvTsqDtl4 {
        char        cPoolId[4];
		char		cBetCentre[4];
};


struct sRcvTsqPool {
        char        cPoolId[4];
        int         nUnits;
        float       fPoolrev;
        float       fDeductVal;
        float       fTaxVal;
        float       fValueBased;
};


struct sRcvTsqHrs {
        char        cRaceHorseNum[11];
        int         nUnits;
        int         nSplUnits;
        float       fTotalRev;
        float       fValueBased;
        float       fHorseRev;
        char        cHorseSts;
};


struct sRcvTsqPay {
        char        cTktNum[17];
        float       fAmtPayable;
        float       fInvVal;
        char        cPayDt[11];
        char        cTktExpDt[11];
        char        cTdsNum[6];
        float       fTdsValue;
        char        cPayoutSts;
};


struct sRcvTsqPayStats {
        char        cPayoutSts;
        float       fInvVal;
        float       fAmtPayable;
        float       fTdsValue;
};


struct sRcvMlq {
        char        cHorseNum[11];
        int         nUnits;
        float       fVal;
};
   

struct sRcvMlqDtl {
        char        cHorseNum[3];
        char        cBetCentre[4];
        int         nUnits;
        float       fAmt;
};


struct sRcvWgrDtl {
        char        cRaceDt[11];
        char        cRaceVenue[4];
        int         numRaces;
        float       fWages;
        float       fAttIncent;
        float       fFoodAllow;
};


struct 	sRcvSwq {
		char		cRaceDt[11];
		float		fRevenue;
};




struct sRcvHwcInit
		{
		char		cRaceDt[11];
		char		cRaceVenue[4];
		char		cRaceNum[3];
};

struct	sRcvHwc 
		{
		int		nPlaceNum;
		char		cHorseNum[3];
		char		cWhiteConeSts;
};

struct sRcvAmm
		{
		char	cRaceDt[11];
		char    cUsrId[5];
		char    cUsrNm[31];
		char    cUsrTyp[5];
		char    cSignInTm[9];
		char	cSignOutTm[9];
		};

struct sRcvVcq
		{
		char	cVoucherNum[17];
		char	cSts;
		float	fAmt;
		};
struct sRcvCashVoucherDtl
	{
		char        cVoucherNum[17];
        char        cTktNum[17];
        float       fTktAmt;
		char 		cSts;
        char        cCrtBtId[5];
        char        cCrtUsrId[5];
        char        cCrtDt[11];
        char        cCrtTm[9];
	};	

#endif		/* !defined (ABS_RCV_TXN_H) */

