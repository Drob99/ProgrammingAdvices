using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContactsDataAccessLayer
{
    public class clsCountryDataAccess
    {
        public static bool GetCountryInfoByID(int ID, ref string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "SELECT * FROM Countries WHERE CountryID = @CountryID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryID", ID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    // Fill the vars
                    CountryName = (string)reader["CountryName"];
                    Code = reader["Code"].ToString();
                    PhoneCode = reader["PhoneCode"].ToString();
                }

                reader.Close();
            }

            catch (Exception ex)
            {
                //Console.Writeline("Error: " + ex.Message); -> Not its place. This is a class library
                isFound = false;
            }

            finally
            {
                connection.Close();
            }

            return isFound;
        }

        public static bool GetCountryInfoByName(ref int ID, string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "SELECT * FROM Countries WHERE CountryName = @CountryName";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryName", CountryName);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    // Fill the vars
                    ID = (int)reader["CountryID"];
                    Code = reader["Code"].ToString();
                    PhoneCode = reader["PhoneCode"].ToString();
                }

                reader.Close();
            }

            catch (Exception ex)
            {
                //Console.Writeline("Error: " + ex.Message); -> Not its place. This is a class library
                isFound = false;
            }

            finally
            {
                connection.Close();
            }

            return isFound;
        }
        
        public static int AddNewCountry(string CountryName, string Code, string PhoneCode)
        {
            int CountryID = -1;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"INSERT INTO Countries
           (CountryName, Code, PhoneCode)
            VALUES
           (@CountryName, @Code, @PhoneCode);

            SELECT SCOPE_IDENTITY();";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryName", CountryName);
            if (Code != "")
                command.Parameters.AddWithValue("@Code", Code);
            else
                command.Parameters.AddWithValue("@Code", System.DBNull.Value);

            if (PhoneCode != "")
                command.Parameters.AddWithValue("@PhoneCode", PhoneCode);
            else
                command.Parameters.AddWithValue("@PhoneCode", System.DBNull.Value);

            try
            {
                connection.Open();
                object result = command.ExecuteScalar();


                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                    CountryID = insertedID;
            }

            catch (Exception ex)
            {
                // Console.WriteLine("Error: " + ex.ToString());
            }

            finally
            {
                connection.Close();
            }
            return CountryID;
        }

        public static bool UpdateCountry(int CountryID, string CountryName, string Code, string PhoneCode)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"UPDATE Countries
            SET
            CountryName = @CountryName,
            Code = @Code,
            PhoneCode = @PhoneCode
            WHERE CountryID = @CountryID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryName", CountryName);
            command.Parameters.AddWithValue("@Code", Code);
            command.Parameters.AddWithValue("@PhoneCode", PhoneCode);
            command.Parameters.AddWithValue("@CountryID", CountryID);


            try
            {
                connection.Open();
                rowsAffected = command.ExecuteNonQuery();
            }

            catch (Exception ex)
            {
                // Console.WriteLine("Error: " + ex.Message);
                return false;
            }
            finally
            {
                connection.Close();
            }
            return rowsAffected > 0;
        }

        public static bool DeleteCountry(int CountryID)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"Delete from Countries
            WHERE CountryID = @CountryID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {
                connection.Open();
                rowsAffected = command.ExecuteNonQuery();
            }

            catch (Exception ex)
            {
                // Console.WriteLine("Error: " + ex.Message);
            }

            finally
            {
                connection.Close();
            }

            return rowsAffected > 0;
        }


        public static DataTable GetAllCountries()
        {
            DataTable dt = new DataTable();
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * from Countries";

            SqlCommand command = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader(); // more than 1 row


                if (reader.HasRows)
                {
                    dt.Load(reader);
                }

                reader.Close();
            }

            catch (Exception ex)
            {
                // Console.WriteLine("Error: " + ex.Message);
            }

            finally
            {
                connection.Close();
            }

            return dt;
        }


        public static bool IsCountryExist(int ID)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "SELECT Found=1 FROM Countries WHERE CountryID = @CountryID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryID", ID);

            try
            {
                connection.Open();
                object result = command.ExecuteScalar();

                isFound = result != null;

                // object result = command.ExecuteReader();
                // isFound = result.HasRows;
                // reader.close()
            }

            catch (Exception ex)
            {

            }

            finally
            {
                connection.Close();
            }

            return isFound;
        }
    
        public static bool IsCountryExist(string Name)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "SELECT Found=1 FROM Countries WHERE CountryName = @CountryName";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryName", Name);

            try
            {
                connection.Open();
                object result = command.ExecuteScalar();

                isFound = result != null;

                // object result = command.ExecuteReader();
                // isFound = result.HasRows;
                // reader.close()
            }

            catch (Exception ex)
            {

            }

            finally
            {
                connection.Close();
            }

            return isFound;
        }
    
    }

}
