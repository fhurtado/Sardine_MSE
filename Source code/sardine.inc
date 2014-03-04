      INTEGER MaxYr,MaxAge,MaxSim
      PARAMETER(MaxYr=200000,MaxAge=20,MaxSim=100)
C
      COMMON / General / Nsim
      INTEGER Nsim
C      Nsim                  - Number of simulations      
      
      COMMON / BiolPar / Nage,Nyear,Weight,Fecu,Matu,Selex,Ninit,NatM,
     +     R0,Steepness,Alpha,Beta1,Beta2,Rerr,Rtype,AlogRPS,
     +     BlogRPS,PhilogRPS 
      INTEGER Nyear,Nage
      REAL*8 Weight(0:MaxAge),Fecu(0:MaxAge),Matu(0:MaxAge)
      REAL*8 Selex(0:MaxAge)
      REAL*8 SelxPNW(0:MaxAge),Ninit(0:MaxAge)
      REAL*8 NatM,R0,Steepness,Alpha,Beta1,Beta2,Rerr,Rtype
      REAL*8 AlogRPS,BlogRPS,PhilogRPS	  
C      Nyear                 - Number of projection years
C      Nage                  - Number of age-classes year      
C      Weight(a)             - Weight-at-age      
C      Matu(a)               - Maturity
C      Fecu(a)               - Fecundity
C      Selex(a)              - Selectivity
C      Ninit(a)              - Initial numbers-at-age
C      NatM                  - Natural mortality
C      R0                    - Virgin recruitment
C      Steepness             - Steepness
C      Alpha,Beta1,Beta2     - SR parameters
C      Rerr                  - Use Recruitment uncertainty?
C      Rtype                 - What rec model to use (0=dome shaped; 1=flat top)

      COMMON / Dynamics / N,B1P,SSB,F,ObsF,Catch,RecRep,AgeN,AgeC
      REAL*8 N(0:MaxYr,0:MaxAge),B1p(MaxSim,0:MaxYr),SSB(MaxSim,0:MaxYr)
      REAL*8 F(MaxSim,0:MaxYr),ObsF(MaxSim,0:MaxYr)
      REAL*8 Catch(MaxSim,0:MaxYr),RecRep(MaxSim,0:MaxYr)
      REAL*8 AgeN(MaxSim,0:MaxYr),AgeC(MaxSim,0:MaxYr)
C      N(y,a)                - Numbers-at-age      
C      B1p(s,y)              - Biomass of 1+ animals for year y and simulation s
C      SSB(s,y)              - SSB for year y and simulation s
C      F(s,y)                - True fishing mortality
C      ObsF(s,y)             - Fishing mortality from HG
C      Catch(s,y)            - Catch by year
C      RecRep(s,y)           - Recruitment by year
C      AgeN(s,y)             - Mean Age of the population
C      AgeC(s,y)             - Mean age of the catch
C      
	  
      COMMON / Assessment / Bhat,Emsymin,Emsymax,Cutoff,FracMin,FracMax,
     +       Maxcatch,OFL,Pstar,OFLmax,SigmaB,Berr,CutOpt,EpsB,OFLopt,
     +       HCRopt,ISEED4,NoOFL
      REAL*8 Bhat,Emsymin,Emsymax,Cutoff,FracMin,FracMax,Maxcatch,OFL
      REAL*8 OFLmax,Pstar,SigmaB,Berr,CutOpt
      REAL*8 EpsB(0:MaxYr)
      INTEGER HCRopt,OFLopt,ISEED4,NoOFL
C      Bhat                  - Estimated biomass
C      Emsy                  - Value of Emsy
C      Cuttoff               - Cutoff parameter of the HG
C      Frac                  - Fraction parameter of the HG
C      Maxcatch              - Maxcatch parameter of the HG
C      SigmaB                - Variance for biomass estimate
C      HCRopt                - Which HCR should be used? 
C      OFLopt                - Which OFL should be used? 

      COMMON / EnvVar / Gtype,ISEED1,ISEED2,ISEED3,G,V,Eps,I,Vdev,
     +       EpsInit,ProwR,SigmaR,Vinit,Ybar,Period,Chi,Power,ProwV,
     +       SigmaV,Phi,MeanSST,SigmaI,Ierr,Verr,UseG,Amplitude,Vrep   
      INTEGER Gtype
      INTEGER ISEED1,ISEED2,ISEED3
      REAL*8 G(0:MaxYr),V(0:MaxYr),Eps(0:MaxYr),I(0:MaxYr),Vdev(0:MaxYr)
      REAL*8 EpsInit,ProwR,SigmaR
      REAL*8 Vinit,Ybar,Period,Chi,Power,ProwV,SigmaV,Phi,MeanSST
      REAL*8 SigmaI,Ierr,Verr,UseG,Amplitude
      REAL*8 Vrep(MaxSim,0:MaxYr)
C      Gtype                 - Type of variables      
C      G(y)                  - Underlying trends in the Environment variables
C      V(y)                  - Environmental variable
C      I(y)                  - Observed environmental variable
C      Eps(y)                - Rec_dev
C      EpsInit               - last Eps
C      ProwR                 - Prow for rec_dev
C      SigmaR                - Sigma for rec_dev
C      Vinit                 - last V
C      Ybar                  - Centering parameter
C      Period                - Period of the signal
C      Chi                   - Parameter for Type 1 relationship
C      Power                 - Parameter for Type 2 relationship
C      SigmaI                - Sigma for measurement error on the environmental index
C      Verr                  - Use environment uncertainty?
C
      COMMON / Sensitivities /  TVselx,TVweight,MultFleet,HyperSt,TVM,
     +       HPSa,Fmex,Fcan,WeightOut,SelxOut,UseAnn,DiffSelx,
     +       SelxSum,WeightSum,SelxMC1,SelxMC2,SelxMCy,SelxPNW,
     +       Weight80s,Weight90s, Myear
      REAL*8 TVselx,TVweight,MultFleet,HyperSt,TVM,HPSa,Fmex,Fcan
      REAL*8 WeightOut,SelxOut,UseAnn,DiffSelx
      REAL*8 SelxSum(0:MaxYr,0:MaxAge),WeightSum(0:MaxYr,0:MaxAge)
      REAL*8 SelxMC1(0:MaxAge),SelxMC2(0:MaxAge),SelxMCy(0:MaxAge)
      REAL*8 Weight80s(0:MaxAge),Weight90s(0:MaxAge),Myear(0:MaxYr)
