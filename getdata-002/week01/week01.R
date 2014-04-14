problem_01<-function(){
  file<-read.csv("question_01.csv")
  file2<-file[file$TYPE==1,]
  file3<-file2[!is.na(file2$VAL),]
  nrow(file3[file3$VAL==24,])
}

problem_03<-function(){
  doc<-xmlTreeParse('./question_04.xml', useInternal=TRUE)
  rootNode<-xmlRoot(doc)
  zip <- xpathSApply(rootNode,"//zipcode",xmlValue)
  length(zip[zip=="21231"])
}

problem_04<-function(){
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  mean(DT$pwgtp15,by=DT$SEX)
  proc.time() - ptm
  
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  tapply(DT$pwgtp15,DT$SEX,mean)
  proc.time() - ptm
  
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  mean(DT[DT$SEX==1,]$pwgtp15)
  mean(DT[DT$SEX==2,]$pwgtp15)
  proc.time() - ptm 
  
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  DT[,mean(pwgtp15),by=SEX]
  proc.time() - ptm 
  
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  sapply(split(DT$pwgtp15,DT$SEX),mean)
  proc.time() - ptm 
  
  DT<-fread("question_05.csv")
  ptm <- proc.time()
  rowMeans(DT)[DT$SEX==1]
  rowMeans(DT)[DT$SEX==2]
  proc.time() - ptm 
}