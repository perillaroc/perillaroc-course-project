best <- function(state, outcome) {
  ## Read outcome data
  ## Check that state and outcome are valid
  ## Return hospital name in that state with lowest 30-day death
  ## rate
  
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
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
  
  data_state<-data_state[data_state[,col_num]!="Not Available",]
  min_value <- min(as.numeric(data_state[,col_num]))
  result <- data_state[as.numeric(data_state[,col_num])==min_value,][[2]]
  sort(result)
}