question01<-function(){
  q1<-read.csv("question01.csv",header=TRUE)
  agricultureLogical <-(q1$AGS==6 & q1$ACR==3 & !is.na(q1$AGS) & !is.na(q1$ACR))
  which(agricultureLogical)
}

question02<-function(){
  q2<- readJPEG("question02.jpg",native=TRUE)
  quantile(q2,probs=c(0.3,0.8))
}

question04<-function(){
  q4_gdp<-read.csv("question03-GDP.csv",header=TRUE)
  q4_edu<-read.csv("question03-Country.csv",header=TRUE)
  q4<-merge(q4_gdp,q4_edu,by.x="X",by.y="CountryCode",all=TRUE)
  q4_nona<- q4[!is.na(q4$Gross.domestic.product.2012),]
  tapply(q4_nona$Gross.domestic.product.2012, q4_nona$Income.Group,mean)
}

question05<-function(){
  q5_gdp<-read.csv("question03-GDP.csv",header=TRUE)
  q5_edu<-read.csv("question03-Country.csv",header=TRUE)
  q5<-merge(q5_gdp,q5_edu,by.x="X",by.y="CountryCode",all=TRUE)
  q5_nona<- q5[!is.na(q5$Gross.domestic.product.2012),]
  q5004<-q5_nona[order(q5_nona$Gross.domestic.product.2012),]
  which(q3004[1:38,"Income.Group"]=="Lower middle income")
}