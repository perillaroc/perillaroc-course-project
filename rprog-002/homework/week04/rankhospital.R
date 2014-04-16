rankhospital <- function(state, outcome, num = "best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  ## Check that state and outcome are valid
  data_state = data[data$State == state,]
  if(nrow(data_state)==0)
  {
    stop("invalid state")
  }
  
  col_num <- -1
  if(outcome == "heart attack"){
    col_num <- 11
  }
  else if(outcome == "heart failure")
  {
    col_num <- 17
  }
  else if(outcome == "pneumonia")
  {
    col_num <- 23
  }
  else
  {
    stop("invalid outcome")
  }
  
  ## Return hospital name in that state with the given rank
  ## 30-day death rate
  
  data_state<-data_state[data_state[,col_num]!="Not Available",]
  results<-data_state[order(as.numeric(data_state[,col_num])),]
  if(num == "best")
    results[[1,2]]
  else if(num == "worst"){
    results[[nrow(results),2]]
  }
  else{
    if(nrow(results)<num){
      c(NA)
    }
    else{
      results[[num,2]]
    }
  }
  
}