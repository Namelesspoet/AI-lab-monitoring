void logWrite(String msg)
{
      memmove(Configuration.LogRow[1],Configuration.LogRow[0],4900);
      memset(Configuration.LogRow[0],0,LOG_LEN);
       String copy = ntp.dateString()  + " " + ntp.timeString() + "." + ntp.ms() + " =>" + msg  + ";";//ntp.dateString()  + " " + ntp.timeString() + "." + ntp.ms()
      copy.toCharArray(Configuration.LogRow[0], LOG_LEN);
      //memset(Configuration.LogRow[50],0,LOG_LEN);// для веб морды
      //strncpy(Configuration.LogRow[0], test , 40);
      Cfg.updateNow();
}
